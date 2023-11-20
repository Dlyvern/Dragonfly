#include "modules/Module.hpp"

std::shared_ptr<rclcpp::Node>Module::m_NodeWithParameters;

Module::Module(const std::string &nameOfNode, QWidget *parent) : rclcpp::Node(nameOfNode), QWidget(parent)
{
    if(!m_NodeWithParameters)
    {
        m_NodeWithParameters = std::make_shared<rclcpp::Node>("PARAMETERS_NODE");
        InitializeParameters();
    }

    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/log", 200);

    m_Modules.emplace_back(this);

    std::thread([this]
    {
        while(rclcpp::ok())
        {
            m_ActionsExecutor.spin();
        }
    }).detach();
}

void Module::InitializeParameters()
{
    if(m_NodeWithParameters == nullptr) return;
    //[Header("SOME SHIT")]
    m_NodeWithParameters->declare_parameter("cw/uptime", 0);
    m_NodeWithParameters->declare_parameter("cw/operator", "None");
    m_NodeWithParameters->declare_parameter("cw/project_name", "DEFAULT");
    m_NodeWithParameters->declare_parameter("cw/winros", false);
    m_NodeWithParameters->declare_parameter("test_level", 1);
}

void Module::RunActionServer()
{
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(void)>>>actions;

    std::map<std::string, std::string>functions;

    std::string function_for_log{" "};

    for(const auto&module : m_Modules)
    {
        actions[module->get_name()] = module->GetActionFunctions();

        for(const auto& function : module->GetActionFunctions())
            functions[module->get_name()] = function.first;
    }

    for(const auto&functions_to_show : functions)
    {
        function_for_log += functions_to_show.first + ": " + functions_to_show.second + "\n";
    }

    Log("Starting Action Server with following functions: ", 0);
    Log(function_for_log, 0);

     m_ActionServer = std::make_shared<ActionServer>();

    m_ActionServer->Start(actions);

    m_ActionsExecutor.add_node(m_ActionServer);
}

void Module::StartNewActionClient(const Command &command, int idClient)
{
    m_ActionClient = std::make_shared<ActionClient>(command, idClient);

    m_ActionClient->Start();

    m_ActionsExecutor.add_node(m_ActionClient);
}

void Module::Log(const std::string &message, int logLevel) const
{
    if(m_LogPublisher == nullptr)
        return;

    std_msgs::msg::String log_msg;

    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H:%M:%S");

    std::string date_time = ss.str();

    std::string name_of_node = this->get_name();

    //[TIME] [NAME]: MESSAGE LOGLEVEL(0 - INFO, 1 - WARN, 2 - ERROR)

    log_msg.data = "[" + date_time + "]" + '|' + "[" + name_of_node + "]: " + message + std::to_string(logLevel); //I know that this looks like a mess...

    m_LogPublisher->publish(log_msg);
}

void Module::SetRunning(bool running)
{
    m_IsRunning = running;
}

bool Module::IsRunning() const
{
    return m_IsRunning;
}

void Module::SetRunInterval(std::chrono::milliseconds runInterval)
{
    m_RunInterval = std::chrono::milliseconds(runInterval);
}

std::chrono::milliseconds Module::GetRunInterval() const
{
    return m_RunInterval;
}

bool Module::IsAlive(const std::chrono::seconds &howMuchToWaitForRespond)
{
    std::unique_lock<std::mutex>unique_lock(m_ActivityMutex);
    return m_ActivityConditionVariable.wait_for(unique_lock, howMuchToWaitForRespond) == std::cv_status::no_timeout;
}

void Module::ActivitySensor()
{
    std::unique_lock<std::mutex>unique_lock(m_ActivityMutex);
    m_ActivityConditionVariable.notify_all();
}

rclcpp::Parameter Module::GetParameter(const std::string &parameter) const
{
    Log("Trying to get parameter '" + parameter + "'", INFO_LEVEL_LOG);

    rclcpp::Parameter return_value = rclcpp::Parameter{parameter};

    try
    {
        if (!this->has_parameter(parameter))
        {
            Log("Unable to get parameter '" + parameter + "': no such key", ERROR_LEVEL_LOG);
            return return_value;
        }
    }

    catch(const rclcpp::exceptions::ParameterNotDeclaredException& exception)
    {
        Log("Parameter '" + parameter +"' not declared", ERROR_LEVEL_LOG);
        return return_value;
    }

    catch (const rclcpp::exceptions::InvalidParametersException& e)
    {
        Log("Unable to get parameter '" + parameter +"': " + e.what(), ERROR_LEVEL_LOG);
        return return_value;
    }

    return this->get_parameter(parameter);
}

Module::~Module() = default;
