// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__SRV__DETAIL__CMD__BUILDER_HPP_
#define ACTION_INTERFACE__SRV__DETAIL__CMD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "action_interface/srv/detail/cmd__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace action_interface
{

namespace srv
{

namespace builder
{

class Init_Cmd_Request_cmd
{
public:
  Init_Cmd_Request_cmd()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::action_interface::srv::Cmd_Request cmd(::action_interface::srv::Cmd_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::srv::Cmd_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::srv::Cmd_Request>()
{
  return action_interface::srv::builder::Init_Cmd_Request_cmd();
}

}  // namespace action_interface


namespace action_interface
{

namespace srv
{

namespace builder
{

class Init_Cmd_Response_res_arg
{
public:
  explicit Init_Cmd_Response_res_arg(::action_interface::srv::Cmd_Response & msg)
  : msg_(msg)
  {}
  ::action_interface::srv::Cmd_Response res_arg(::action_interface::srv::Cmd_Response::_res_arg_type arg)
  {
    msg_.res_arg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::action_interface::srv::Cmd_Response msg_;
};

class Init_Cmd_Response_result
{
public:
  Init_Cmd_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Cmd_Response_res_arg result(::action_interface::srv::Cmd_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return Init_Cmd_Response_res_arg(msg_);
  }

private:
  ::action_interface::srv::Cmd_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::action_interface::srv::Cmd_Response>()
{
  return action_interface::srv::builder::Init_Cmd_Response_result();
}

}  // namespace action_interface

#endif  // ACTION_INTERFACE__SRV__DETAIL__CMD__BUILDER_HPP_
