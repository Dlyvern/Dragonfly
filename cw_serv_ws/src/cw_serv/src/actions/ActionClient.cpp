#include "actions/ActionClient.hpp"


ActionClient::ActionClient(const Command &command, int id, std::chrono::seconds serverTimeOut) : rclcpp::Node("ActionClient"),
m_Name{"ActionClient" + std::to_string(id)},
m_Target{command.GetTarget()},
m_ClientId{id},
m_Operation{command.GetOperation()},
m_Arguments{command.GetArguments()},
m_TimeLimit{command.GetTimeLimit()},
m_ServerTimeOut{serverTimeOut}
{
    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/log", 200);

    m_ActionClient = rclcpp_action::create_client<action_interface::action::Cmd>(this, "cmd");

    m_ConnectionTimer = this->create_wall_timer(std::chrono::milliseconds(0), std::bind(&ActionClient::SendGoal, this));
}

void ActionClient::Start()
{

}

void ActionClient::SendGoal()
{
    int failure_times{0};

    while(!m_IsConnected)
    {
        m_IsConnected = m_ActionClient->wait_for_action_server(m_ServerTimeOut);

        if(!m_IsConnected)
        {
            Log("Could not connect to action server. Trying one more time", 1);
            failure_times++;

            if(failure_times > 5)
            {
                Log("Could not connect to action server more than 5 timer. Aborting action client", 2);
                m_ConnectionTimer->cancel();
                return;
            }
        }
    }

    Log("Connected to action server. Starting to send a goal to action server", 0);

    m_ConnectionTimer->cancel();

    using namespace std::placeholders;

    auto send_goal_options = rclcpp_action::Client<action_interface::action::Cmd>::SendGoalOptions();

    send_goal_options.goal_response_callback = std::bind(&ActionClient::GoalResponse, this, std::placeholders::_1);

    send_goal_options.feedback_callback = std::bind(&ActionClient::GoalFeedback, this, _1, _2);

    send_goal_options.result_callback = std::bind(&ActionClient::GoalResult, this, _1);

    auto goal_msg = action_interface::action::Cmd::Goal();

    goal_msg.target = m_Target;
    goal_msg.operation = m_Operation;
    goal_msg.args = m_Arguments;
    goal_msg.time_limit = m_TimeLimit;

    m_ActionClient->async_send_goal(goal_msg, send_goal_options);
}

void ActionClient::GoalFeedback(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr, const std::shared_ptr<const action_interface::action::Cmd::Feedback> feedback)
{
    Log(&"Progress: " [ feedback->progress], 0);
}

void ActionClient::GoalResponse(rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::SharedPtr future)
{
    auto goal_handle = future.get();

    if (!goal_handle)
    {
        Log("Goal was rejected by server", 2);
    }
    else
    {
        Log("Goal accepted by server, waiting for result", 0);
    }
}


void ActionClient::GoalResult(const rclcpp_action::ClientGoalHandle<action_interface::action::Cmd>::WrappedResult & result)
{
    switch (result.code)
    {
        case rclcpp_action::ResultCode::SUCCEEDED:
            break;
        case rclcpp_action::ResultCode::ABORTED:
            Log("Goal was aborted", 2);
            return;
        case rclcpp_action::ResultCode::CANCELED:
            Log("Goal was canceled", 2);
            return;
        default:
            Log("Unknown result code", 2);
            return;
    }

    Log("Action done with result " + result.result->res_arg, 0);
}

void ActionClient::Log(const std::string &message, int levelLog)
{
    if(m_LogPublisher == nullptr)
        return;

    std_msgs::msg::String log_msg;

    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H:%M:%S");

    std::string date_time = ss.str();

    std::string name_of_node = m_Name;

    //[TIME] [NAME]: MESSAGE LOGLEVEL(0 - INFO, 1 - WARN, 2 - ERROR)

    log_msg.data = "[" + date_time + "]" + '|' + "[" + name_of_node + "]: " + message + std::to_string(levelLog); //I know that this looks like a mess...

    m_LogPublisher->publish(log_msg);
}
