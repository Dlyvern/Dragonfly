#include "modules/Module.hpp"

std::shared_ptr<ActionServer>Module::m_ActionServer{nullptr};
std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>Module::allActions_;

Module::Module(const std::string &nameOfNode, QWidget *parent) : rclcpp::Node(nameOfNode), QWidget(parent), m_Name{nameOfNode} {
    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/log", 200);

    if (!m_ActionServer)
    {
        m_ActionServer = std::make_shared<ActionServer>();
//
//        std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::string (void)>>>functions;
//
//        Action action;
//        action.target = "Server";
//        action.operation = "Test";
//        action.function = []()->std::string
//        {
//            return {"test_action_completed"};
//        };
//
//        std::unordered_map<std::string, std::function<std::string (void)>>fun;
//
//        fun[action.operation] = action.function;
//
//        functions[action.target] = fun;

        m_ActionServer->Start(allActions_);

        std::thread([]{spin(m_ActionServer);}).detach();
    }
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

//    std::string name_of_node = this->get_name();

    std::string name_of_node = m_Name;

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

    try
    {
        if (!this->has_parameter(parameter))
        {
            Log("Unable to get parameter '" + parameter + "': no such key", ERROR_LEVEL_LOG);
            return {};
        }
    }

    catch(const rclcpp::exceptions::ParameterNotDeclaredException& exception)
    {
        Log("Parameter '" + parameter +"' not declared", ERROR_LEVEL_LOG);
        return {};
    }

    catch (const rclcpp::exceptions::InvalidParametersException& e)
    {
        Log("Unable to get parameter '" + parameter +"': " + e.what(), ERROR_LEVEL_LOG);
        return {};
    }

    return this->get_parameter(parameter);
}

Module::~Module() = default;