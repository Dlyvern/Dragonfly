#include "modules/Logger.hpp"

Logger::Logger(const std::string &nameOfNode, QWidget *parent)
        : Module(nameOfNode, parent)
{
    m_DirName = "../logs";
    m_LogSub = this->create_subscription<std_msgs::msg::String>("/cw/log", 500, std::bind(&Logger::EventCallback, this, std::placeholders::_1));
    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/logger", 10);
}

void Logger::Start()
{
    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H-%M-%S");

    std::string date_time = ss.str();

    m_FileName = "cw_log " + date_time + ".txt";

    if (boost::filesystem::exists(m_DirName))
    {
        Log(m_DirName + " already exists", WARN_LEVEL_LOG);
        try
        {
            boost::filesystem::remove_all(m_DirName);
            Log("Old " + m_DirName + " directory successfully deleted", INFO_LEVEL_LOG);
        }
        catch (const boost::filesystem::filesystem_error& e)
        {
            Log("Error while deleting " + m_DirName + " error: " + e.what(), ERROR_LEVEL_LOG);
        }
    }

    boost::filesystem::create_directory(m_DirName);

    Log("Directory " + m_DirName + " successfully created. Full path: " + boost::filesystem::canonical(m_DirName).string(), INFO_LEVEL_LOG);

    boost::filesystem::path folder_path("./" + m_DirName);

    m_FullPathToLogFile = folder_path / m_FileName;

    try
    {
        boost::filesystem::ofstream log_file(m_FullPathToLogFile);

        if (!log_file.is_open())
            throw std::runtime_error("Error while creating log file");

        log_file.close();

        Log("Log file created successfully", INFO_LEVEL_LOG);
    }
    catch (const  boost::filesystem::filesystem_error& e)
    {
        Log(e.what(), ERROR_LEVEL_LOG);
    }

    SetRunInterval(std::chrono::milliseconds (100));
    SetRunning(true);
    this->runThread_ = std::thread([this]{Run();});
    runThread_.detach();
}

void Logger::Run()
{
    while(IsRunning())
    {
        ActivitySensor();
        ProcessEvents();
        std::this_thread::sleep_for(GetRunInterval());
    }
}

void Logger::EventCallback(const std_msgs::msg::String::SharedPtr msg)
{
    m_Events.emplace_back(std::move(msg->data));
}

void Logger::ProcessEvents()
{
    while(!m_Events.empty())
    {
        std::string event = m_Events.front();
        m_Events.erase(m_Events.begin());
        int level_of_log = event.back() - '0';
        event.erase(event.end() - 1);

        switch(level_of_log)
        {
            case INFO_LEVEL_LOG: //0
                RCLCPP_INFO(this->get_logger(), "%s", event.c_str());
                break;

            case WARN_LEVEL_LOG: //1
                RCLCPP_WARN(this->get_logger(), "%s", event.c_str());
                break;

            case ERROR_LEVEL_LOG: //2
                RCLCPP_ERROR(this->get_logger(), "%s", event.c_str());
                break;

            default:
                RCLCPP_ERROR(this->get_logger(), "Logger got message but level of log was not declared");
                break;
        }

        boost::filesystem::ofstream log_file(m_FullPathToLogFile);

        if (!log_file.is_open())
            throw std::runtime_error("Error while creating log file");

        log_file << event + "\n";

        log_file.close();
    }
}

//Checks if 24 hours have passed since the last log file was created
void Logger::CheckTime()
{
//    double current_time_diff = std::time(nullptr) - (std::chrono::steady_clock::now() - init_time_mono_).count() - init_time_;
//
//    if (std::abs(current_time_diff) < 86400) return; //If 24 have not passed
//
//    time_diff_ = current_time_diff;
//
//    std::string new_file_name = "./logs/cwlog-" + get_current_timestamp(time_diff_) + ".txt";
//
//    std::ofstream new_file(new_file_name);
//
//    for (const auto& msg : logs_)
//    {
//        std::string s = create_msg(msg, time_diff_);
//        new_file << s << std::endl;
//    }
//
//    new_file.close();
//    log("Time has changed, moving logfile to " + new_file_name);
//    std::filesystem::remove(fname);
//    fname = new_file_name;
}

Logger::~Logger()
= default;

std::unordered_map<std::string, std::function<void(void)>> Logger::GetActionFunctions()
{
    return {};
}


