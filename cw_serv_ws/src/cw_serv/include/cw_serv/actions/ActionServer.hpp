#ifndef ACTION_SERVER_HPP
#define ACTION_SERVER_HPP

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "action_interface/action/cmd.hpp"
#include <std_msgs/msg/string.hpp>
#include "rclcpp_components/register_node_macro.hpp"

#ifndef RUN_PARAMETERS_HPP
#include "cw_structs/RunParameters.hpp"
#endif

class ActionServer : public rclcpp::Node
{
private:
    std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>*m_AllActionsFromModulesAndSubmodules;
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;

    std::unordered_map<rclcpp_action::GoalUUID,  std::unordered_map<std::shared_ptr<const action_interface::action::Cmd::Goal>, RunParameters>>m_Goals;

    rclcpp_action::Server<action_interface::action::Cmd>::SharedPtr m_ActionServer;

    std::string m_Name;

    std::future<std::pair<std::string, bool>>m_WorkFuture;

    std::function<std::pair<std::string, bool>(RunParameters& runParameters)> m_ExecuteFunction;

    rclcpp_action::GoalResponse HandleGoal(const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal);

    rclcpp_action::CancelResponse HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

    void HandleAcceptedGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle);

    std::pair<std::string, bool> Work();

    void Log(const std::string&message, int levelLog);

public:
    ActionServer();

    void Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>& actions);

    virtual ~ActionServer();
};

#endif //ACTION_SERVER_HPP