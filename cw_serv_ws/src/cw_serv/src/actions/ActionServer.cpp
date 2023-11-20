#include "actions/ActionServer.hpp"

ActionServer::ActionServer() : rclcpp::Node("ActionServer")
{
    m_LogPublisher = this->create_publisher<std_msgs::msg::String>("/cw/log", 200);

    m_ActionServer = rclcpp_action::create_server<action_interface::action::Cmd>
    (
            this,
            "cmd",
            std::bind(&ActionServer::HandleGoal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&ActionServer::HandleCancelGoal, this, std::placeholders::_1),
            std::bind(&ActionServer::HandleAcceptedGoal, this, std::placeholders::_1)
    );
}

void ActionServer::Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<void(void)>>> &actions)
{
    m_AllActionsFromModulesAndSubmodules = actions;
    Log("Action server is running", 0);
    //Work();
}

void ActionServer::Work()
{
    while (rclcpp::ok())
    {
        if(!m_ExecuteFunction)
        {
            RCLCPP_INFO(this->get_logger(), "No work");
            continue;
        }

        RCLCPP_INFO(this->get_logger(), "Executing the goal...");

        try
        {
            m_ExecuteFunction();
        }


        catch (std::exception &ex)
        {
            RCLCPP_ERROR(this->get_logger(), "Action server failed while executing action callback: \"%s\"", ex.what());
            return;
        }
    }
}

rclcpp_action::GoalResponse ActionServer::HandleGoal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal)
{
    m_Goals[uuid] = goal;

    std::string target  = goal->target[0];
    std::string operation = goal->operation;

    Log("Finding " + target + " with function " + operation, 0);

    //m_ExecuteFunction = m_AllActionsFromModulesAndSubmodules.find(target)->second.find(operation)->second;

    if(!m_ExecuteFunction)
    {
        Log("Could not find a function to execute. Rejecting the goal", 2);
        return rclcpp_action::GoalResponse::REJECT;
    }

    Log("Found a function to execute. Accepting the goal", 2);

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse ActionServer::HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    goal_handle->abort(nullptr);

    return rclcpp_action::CancelResponse::REJECT;
}

void ActionServer::HandleAcceptedGoal(const std::shared_ptr< rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    Log("Got accepted goal", 0);

    //goal_handle->execute();
   // std::thread{std::bind(&ActionServer::E, this, _1), goal_handle}.detach();
}

void ActionServer::Log(const std::string &message, int levelLog)
{
    if(m_LogPublisher == nullptr)
        return;

    std_msgs::msg::String log_msg;

    std::time_t time = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now());

    std::stringstream ss;

    ss << std::put_time(std::localtime(&time), "%d-%m-%y %H:%M:%S");

    std::string date_time = ss.str();

    std::string name_of_node = this->get_name();

    //[TIME] [NAME]: MESSAGE LOGLEVEL(0 - INFO, 1 - WARN, 2 - ERROR)

    log_msg.data = "[" + date_time + "]" + '|' + "[" + name_of_node + "]: " + message + std::to_string(levelLog); //I know that this looks like a mess...

    m_LogPublisher->publish(log_msg);
}


ActionServer::~ActionServer() = default;

