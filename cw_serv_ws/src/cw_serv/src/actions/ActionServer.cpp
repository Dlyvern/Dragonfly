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

void ActionServer::Start(std::unordered_map<std::string, std::unordered_map<std::string, std::function<std::pair<std::string, bool>(RunParameters& runParameters)>>>&actions)
{
    m_AllActionsFromModulesAndSubmodules = &actions;
    Log("Action server is running", 0);
    //Work();
}

void ActionServer::HandleAcceptedGoal(const std::shared_ptr< rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    rclcpp::Rate loop_rate(1);

    auto feedback = std::make_shared<action_interface::action::Cmd::Feedback>();
    auto result = std::make_shared<action_interface::action::Cmd::Result>();

    feedback->progress = 0;

    m_WorkFuture = std::async(std::launch::async, [this]{ return Work();});

    while(true)
    {
        if (goal_handle->is_canceling())
        {
            result->res = false;
            result->res_arg = "Goal canceled";
            goal_handle->canceled(result);
            Log("Goal canceled", 2);
            return;
        }

        if(m_WorkFuture.wait_for(std::chrono::milliseconds(1)) == std::future_status::ready)
        {
            break;
        }

        feedback->progress++;
        goal_handle->publish_feedback(feedback);
        loop_rate.sleep();
    }

    if(!rclcpp::ok())
    {
        result->res = false;
        result->res_arg = "RCLCPP IS NOT OK";
        goal_handle->succeed(result);
        return;
    }

    auto return_result = m_WorkFuture.get();
    result->res = return_result.second;
    result->res_arg = return_result.first;
    goal_handle->succeed(result);
}

std::pair<std::string, bool> ActionServer::Work()
{
    std::pair<std::string, bool>result;

    if(!m_ExecuteFunction)
    {
        Log("No work", 0);
        return {"No work", false};
    }


    //FIX RUN_PARAMETERS IN WORK METHOD
    try
    {
        result = m_ExecuteFunction(m_Goals.begin()->second.begin()->second);
    }

    catch (std::exception &ex)
    {
        return {R"(Action server failed while executing action callback: \"%s\"", ex.what())", false};
    }

    return result;
}

rclcpp_action::GoalResponse ActionServer::HandleGoal(const rclcpp_action::GoalUUID &uuid, std::shared_ptr<const action_interface::action::Cmd::Goal> goal)
{
    std::string target  = goal->target[0];
    std::string operation = goal->operation;

    Log("Finding " + target + " with function " + operation, 0);

    auto operations = m_AllActionsFromModulesAndSubmodules->find(target);

    if(operations == m_AllActionsFromModulesAndSubmodules->end())
    {
        Log("No target. Rejecting the goal", 2);
        return rclcpp_action::GoalResponse::REJECT;
    }

    auto second_map = operations->second;

    auto it = second_map.find(operation);

    if(it == second_map.end())
    {
        Log("No operation. Rejecting the goal", 2);
        return rclcpp_action::GoalResponse::REJECT;
    }

    m_ExecuteFunction = it->second;

    RunParameters runParameters;
    runParameters.arguments = goal->args;
    runParameters.timeLimit = goal->time_limit;

    m_Goals[uuid][goal] = runParameters;

    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse ActionServer::HandleCancelGoal(const std::shared_ptr<rclcpp_action::ServerGoalHandle<action_interface::action::Cmd>> goal_handle)
{
    goal_handle->abort(nullptr);

    return rclcpp_action::CancelResponse::REJECT;
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

    std::string name_of_node = "Action server";

    //[TIME] [NAME]: MESSAGE LOGLEVEL(0 - INFO, 1 - WARN, 2 - ERROR)

    log_msg.data = "[" + date_time + "]" + '|' + "[" + name_of_node + "]: " + message + std::to_string(levelLog); //I know that this looks like a mess...

    m_LogPublisher->publish(log_msg);
}

ActionServer::~ActionServer() = default;

//RCLCPP_COMPONENTS_REGISTER_NODE(ActionServer)