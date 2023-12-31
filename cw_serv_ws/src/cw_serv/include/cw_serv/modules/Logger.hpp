#ifndef LOGGER_HPP
#define LOGGER_HPP

#ifndef MODULE_HPP
#include "Module.hpp"
#endif

#include "boost/filesystem.hpp"


class Logger : public Module
{
private:
    void Run() override;

    std::vector<std::string> m_Events;
    std::vector<std::string> m_Logs;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr m_LogSub;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr m_Publisher;

    std::string m_FileName; //File where to store logs
    std::string m_DirName; //Dir where FileName will be stored

    boost::filesystem::path m_FullPathToLogFile;

public:
    explicit Logger(const std::string &nameOfNode);

    void CheckTime();

    void Start() override;

    void EventCallback(const std_msgs::msg::String::SharedPtr msg);

    void ProcessEvents();

    virtual ~Logger();

};

#endif //LOGGER_HPP
