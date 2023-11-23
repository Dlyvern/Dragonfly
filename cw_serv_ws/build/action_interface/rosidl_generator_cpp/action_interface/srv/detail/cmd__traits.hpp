// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__SRV__DETAIL__CMD__TRAITS_HPP_
#define ACTION_INTERFACE__SRV__DETAIL__CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interface/srv/detail/cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Cmd_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::srv::Cmd_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::srv::Cmd_Request & msg)
{
  return action_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::srv::Cmd_Request>()
{
  return "action_interface::srv::Cmd_Request";
}

template<>
inline const char * name<action_interface::srv::Cmd_Request>()
{
  return "action_interface/srv/Cmd_Request";
}

template<>
struct has_fixed_size<action_interface::srv::Cmd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::srv::Cmd_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface::srv::Cmd_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Cmd_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << ", ";
  }

  // member: res_arg
  {
    out << "res_arg: ";
    rosidl_generator_traits::value_to_yaml(msg.res_arg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }

  // member: res_arg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res_arg: ";
    rosidl_generator_traits::value_to_yaml(msg.res_arg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::srv::Cmd_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::srv::Cmd_Response & msg)
{
  return action_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::srv::Cmd_Response>()
{
  return "action_interface::srv::Cmd_Response";
}

template<>
inline const char * name<action_interface::srv::Cmd_Response>()
{
  return "action_interface/srv/Cmd_Response";
}

template<>
struct has_fixed_size<action_interface::srv::Cmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::srv::Cmd_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface::srv::Cmd_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface::srv::Cmd>()
{
  return "action_interface::srv::Cmd";
}

template<>
inline const char * name<action_interface::srv::Cmd>()
{
  return "action_interface/srv/Cmd";
}

template<>
struct has_fixed_size<action_interface::srv::Cmd>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface::srv::Cmd_Request>::value &&
    has_fixed_size<action_interface::srv::Cmd_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface::srv::Cmd>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface::srv::Cmd_Request>::value &&
    has_bounded_size<action_interface::srv::Cmd_Response>::value
  >
{
};

template<>
struct is_service<action_interface::srv::Cmd>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface::srv::Cmd_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface::srv::Cmd_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ACTION_INTERFACE__SRV__DETAIL__CMD__TRAITS_HPP_
