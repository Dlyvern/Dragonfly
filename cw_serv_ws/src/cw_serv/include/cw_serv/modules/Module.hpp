#ifndef MODULE_HPP
#define MODULE_HPP

#ifndef INFO_LEVEL_LOG
#define INFO_LEVEL_LOG 0
#endif

#ifndef WARN_LEVEL_LOG
#define WARN_LEVEL_LOG 1
#endif

#ifndef ERROR_LEVEL_LOG
#define ERROR_LEVEL_LOG 2
#endif

#ifndef ACTION_SERVER_HPP
#include "actions/ActionServer.hpp"
#endif

#ifndef ACTION_CLIENT_HPP
#include "actions/ActionClient.hpp"
#endif

#ifndef COMMAND_HPP
#include "cw_structs/Command.hpp"
#endif

#include "QWidget"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "QSettings"

class Module : public rclcpp::Node, public QWidget
{
private:
    std::shared_ptr<ActionClient>m_ActionClient{nullptr};
    std::shared_ptr<ActionServer>m_ActionServer{nullptr};
    rclcpp::executors::MultiThreadedExecutor m_ActionsExecutor;

    std::string m_Name{"NOT_SET"};

    std::mutex m_ActivityMutex;
    std::condition_variable m_ActivityConditionVariable;

    std::chrono::milliseconds m_RunInterval{1000};

    bool m_IsRunning{false};

    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;


    struct Action
    {
        std::string target;
        std::string operation;
        std::function<std::string(void)> function;
    };

public slots:
    void Log(const std::string &message, int logLevel) const;

protected:
    std::thread runThread_;

    virtual void Run() = 0;

    void ActivitySensor();

    void SetRunning(bool running);

    rclcpp::Parameter GetParameter(const std::string &parameter) const;

    std::chrono::milliseconds GetRunInterval() const;

    void SetRunInterval(std::chrono::milliseconds runInterval);

    void RunActionServer();

    [[nodiscard]]virtual std::unordered_map<std::string, std::function<void(void)>> GetActionFunctions() = 0;

    void StartNewActionClient(const Command& command, int idClient);

public:

    explicit Module(const std::string& nameOfNode, QWidget *parent = nullptr);

    virtual void Start() = 0;

    bool IsAlive(const std::chrono::seconds &howMuchToWaitForRespond);

    bool IsRunning() const;

    virtual ~Module();
};

#endif //MODULE_HPP