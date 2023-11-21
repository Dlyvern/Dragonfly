#ifndef ACTION_CLIENT_HPP
#define ACTION_CLIENT_HPP

#include <functional>
#include <future>
#include <memory>
#include <string>
#include <sstream>

#include "action_interface/action/cmd.hpp"

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#ifndef COMMAND_HPP
#include "cw_structs/Command.hpp"
#endif

#include <std_msgs/msg/string.hpp>


class ActionClient : public rclcpp::Node
{
private:
    std::shared_ptr<rclcpp::Publisher<std_msgs::msg::String>>m_LogPublisher;

    rclcpp_action::Client<action_interface::action::Cmd>::SharedPtr m_ActionClient;
    rclcpp::TimerBase::SharedPtr m_ConnectionTimer;

    std::function<void(const std::string& message)>m_DoneCallback;

    std::string m_Name{"NOT_SET"};

    std::vector<std::string> m_Target{};
    int m_ClientId{0};
    std::string m_Operation{" "};
    std::vector<std::string>m_Arguments{};
    int32_t m_TimeLimit{0};
    int32_t m_Progress{0};

    std::chrono::seconds m_ServerTimeOut;

    bool m_IsConnected{false};

    void Log(const std::string&message, int levelLog);


    void SendGoal();

    void GoalResponse(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr future);

    void GoalFeedback(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr, const std::shared_ptr<const action_interface::action::Cmd::Feedback> feedback);

    void GoalResult(const rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::WrappedResult & result);

public:
    ActionClient(const Command &command, int id,std::chrono::seconds serverTimeOut = std::chrono::seconds(10));

    void Start(std::function<void(const std::string& message)>&doneCallback);
};

#endif //ACTION_CLIENT_HPP