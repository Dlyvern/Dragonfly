#ifndef ACTION_SERVER_HPP
#define ACTION_SERVER_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interface/action/cmd.hpp"
#include <std_msgs/msg/string.hpp>
#include "rclcpp_components/register_node_macro.hpp"

class ActionServer : public rclcpp::Node
{
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::string (void)>>> m_AllActionsFromModulesAndSubmodules;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;

    std::unordered_map<rclcpp_action::GoalUUID, std::shared_ptr<const action_interface::action::Cmd::Goal>>m_Goals;

    rclcpp_action::Server<action_interface::action::Cmd>::SharedPtr m_ActionServer;

    std::string m_Name;

    std::future<std::string>m_WorkFuture;

    std::function<std::string(void)> m_ExecuteFunction;

    rclcpp_action::GoalResponse HandleGoal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal);

    rclcpp_action::CancelResponse HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

    void HandleAcceptedGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

    std::string Work();

    void Log(const std::string&message, int levelLog);

public:
    ActionServer();

    void Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::string (void)>>>& actions);

    virtual ~ActionServer();
};

#endif //ACTION_SERVER_HPP