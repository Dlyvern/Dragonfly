#ifndef BASE_HPP
#define BASE_HPP

#ifndef INFO_LEVEL_LOG
#define INFO_LEVEL_LOG 0
#endif

#ifndef WARN_LEVEL_LOG
#define WARN_LEVEL_LOG 1
#endif

#ifndef ERROR_LEVEL_LOG
#define ERROR_LEVEL_LOG 2
#endif

#ifndef COMMAND_HPP
#include "cw_structs/Command.hpp"
#endif

#ifndef RUN_PARAMETERS_HPP
#include "cw_structs/RunParameters.hpp"
#endif

#ifndef ACTION_SERVER_HPP
#include "actions/ActionServer.hpp"
#endif

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class Base : public rclcpp::Node
{
private:
    std::string m_Name{"NOT_SET"};

    std::chrono::milliseconds m_RunInterval{1000};

    bool m_IsRunning{false};

    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;

    static std::shared_ptr<ActionServer>m_ActionServer;

protected:

    static std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>allActions_;

    virtual void Run() = 0;

    void SetRunning(bool running);

    rclcpp::Parameter GetParameter(const std::string &parameter) const;

    std::chrono::milliseconds GetRunInterval() const;

    void SetRunInterval(std::chrono::milliseconds runInterval);

    void Log(const std::string &message, int logLevel) const;
public:

    explicit Base(const std::string& nameOfNode);

    virtual void Start() = 0;

    bool IsRunning() const;

    virtual ~Base();
};

#endif //BASE_HPP