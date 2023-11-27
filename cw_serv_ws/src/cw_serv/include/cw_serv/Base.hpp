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

#include "QWidget"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "QSettings"


class Base : public rclcpp::Node, public QWidget
{
private:
    static std::shared_ptr<ActionServer>m_ActionServer;
    std::string m_Name{"NOT_SET"};

    std::chrono::milliseconds m_RunInterval{1000};

    bool m_IsRunning{false};

    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;

protected:

    static std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>allActions_;

    virtual void Run() = 0;

    void SetRunning(bool running);

    rclcpp::Parameter GetParameter(const std::string &parameter) const;

    std::chrono::milliseconds GetRunInterval() const;

    void SetRunInterval(std::chrono::milliseconds runInterval);

public:

    explicit Base(const std::string& nameOfNode, QWidget *parent = nullptr);

    virtual void Start() = 0;

    bool IsRunning() const;

    virtual ~Base();

public slots:
    void Log(const std::string &message, int logLevel) const;
};

#endif //BASE_HPP
