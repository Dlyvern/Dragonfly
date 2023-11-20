// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interface:action/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__CMD__BUILDER_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interface/action/detail/cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_Goal_time_limit
{
public:
  explicit Init_Cmd_Goal_time_limit(::action_interface::action::Cmd_Goal & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_Goal time_limit(::action_interface::action::Cmd_Goal::_time_limit_type arg)
  {
    msg_.time_limit = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_Goal msg_;
};

class Init_Cmd_Goal_args
{
public:
  explicit Init_Cmd_Goal_args(::action_interface::action::Cmd_Goal & msg)
  : msg_(msg)
  {}
  Init_Cmd_Goal_time_limit args(::action_interface::action::Cmd_Goal::_args_type arg)
  {
    msg_.args = std::move(arg);
    return Init_Cmd_Goal_time_limit(msg_);
  }

private:
  ::action_interface::action::Cmd_Goal msg_;
};

class Init_Cmd_Goal_operation
{
public:
  explicit Init_Cmd_Goal_operation(::action_interface::action::Cmd_Goal & msg)
  : msg_(msg)
  {}
  Init_Cmd_Goal_args operation(::action_interface::action::Cmd_Goal::_operation_type arg)
  {
    msg_.operation = std::move(arg);
    return Init_Cmd_Goal_args(msg_);
  }

private:
  ::action_interface::action::Cmd_Goal msg_;
};

class Init_Cmd_Goal_target
{
public:
  Init_Cmd_Goal_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_Goal_operation target(::action_interface::action::Cmd_Goal::_target_type arg)
  {
    msg_.target = std::move(arg);
    return Init_Cmd_Goal_operation(msg_);
  }

private:
  ::action_interface::action::Cmd_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_Goal>()
{
  return action_interface::action::builder::Init_Cmd_Goal_target();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_Result_res_arg
{
public:
  explicit Init_Cmd_Result_res_arg(::action_interface::action::Cmd_Result & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_Result res_arg(::action_interface::action::Cmd_Result::_res_arg_type arg)
  {
    msg_.res_arg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_Result msg_;
};

class Init_Cmd_Result_res
{
public:
  Init_Cmd_Result_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_Result_res_arg res(::action_interface::action::Cmd_Result::_res_type arg)
  {
    msg_.res = std::move(arg);
    return Init_Cmd_Result_res_arg(msg_);
  }

private:
  ::action_interface::action::Cmd_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_Result>()
{
  return action_interface::action::builder::Init_Cmd_Result_res();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_Feedback_progress
{
public:
  Init_Cmd_Feedback_progress()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::Cmd_Feedback progress(::action_interface::action::Cmd_Feedback::_progress_type arg)
  {
    msg_.progress = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_Feedback>()
{
  return action_interface::action::builder::Init_Cmd_Feedback_progress();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_SendGoal_Request_goal
{
public:
  explicit Init_Cmd_SendGoal_Request_goal(::action_interface::action::Cmd_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_SendGoal_Request goal(::action_interface::action::Cmd_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_SendGoal_Request msg_;
};

class Init_Cmd_SendGoal_Request_goal_id
{
public:
  Init_Cmd_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_SendGoal_Request_goal goal_id(::action_interface::action::Cmd_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Cmd_SendGoal_Request_goal(msg_);
  }

private:
  ::action_interface::action::Cmd_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_SendGoal_Request>()
{
  return action_interface::action::builder::Init_Cmd_SendGoal_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_SendGoal_Response_stamp
{
public:
  explicit Init_Cmd_SendGoal_Response_stamp(::action_interface::action::Cmd_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_SendGoal_Response stamp(::action_interface::action::Cmd_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_SendGoal_Response msg_;
};

class Init_Cmd_SendGoal_Response_accepted
{
public:
  Init_Cmd_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_SendGoal_Response_stamp accepted(::action_interface::action::Cmd_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Cmd_SendGoal_Response_stamp(msg_);
  }

private:
  ::action_interface::action::Cmd_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_SendGoal_Response>()
{
  return action_interface::action::builder::Init_Cmd_SendGoal_Response_accepted();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_GetResult_Request_goal_id
{
public:
  Init_Cmd_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::action::Cmd_GetResult_Request goal_id(::action_interface::action::Cmd_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_GetResult_Request>()
{
  return action_interface::action::builder::Init_Cmd_GetResult_Request_goal_id();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_GetResult_Response_result
{
public:
  explicit Init_Cmd_GetResult_Response_result(::action_interface::action::Cmd_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_GetResult_Response result(::action_interface::action::Cmd_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_GetResult_Response msg_;
};

class Init_Cmd_GetResult_Response_status
{
public:
  Init_Cmd_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_GetResult_Response_result status(::action_interface::action::Cmd_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Cmd_GetResult_Response_result(msg_);
  }

private:
  ::action_interface::action::Cmd_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_GetResult_Response>()
{
  return action_interface::action::builder::Init_Cmd_GetResult_Response_status();
}

}  // namespace action_interface


namespace action_interface
{

namespace action
{

namespace builder
{

class Init_Cmd_FeedbackMessage_feedback
{
public:
  explicit Init_Cmd_FeedbackMessage_feedback(::action_interface::action::Cmd_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::action_interface::action::Cmd_FeedbackMessage feedback(::action_interface::action::Cmd_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::action::Cmd_FeedbackMessage msg_;
};

class Init_Cmd_FeedbackMessage_goal_id
{
public:
  Init_Cmd_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_FeedbackMessage_feedback goal_id(::action_interface::action::Cmd_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Cmd_FeedbackMessage_feedback(msg_);
  }

private:
  ::action_interface::action::Cmd_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::action::Cmd_FeedbackMessage>()
{
  return action_interface::action::builder::Init_Cmd_FeedbackMessage_goal_id();
}

}  // namespace action_interface

#endif  // ACTION_INTERFACE__ACTION__DETAIL__CMD__BUILDER_HPP_
