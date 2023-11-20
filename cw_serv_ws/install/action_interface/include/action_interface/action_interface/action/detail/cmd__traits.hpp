// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from action_interface:action/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__CMD__TRAITS_HPP_
#define ACTION_INTERFACE__ACTION__DETAIL__CMD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "action_interface/action/detail/cmd__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    if (msg.target.size() == 0) {
      out << "target: []";
    } else {
      out << "target: [";
      size_t pending_items = msg.target.size();
      for (auto item : msg.target) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: operation
  {
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
    out << ", ";
  }

  // member: args
  {
    if (msg.args.size() == 0) {
      out << "args: []";
    } else {
      out << "args: [";
      size_t pending_items = msg.args.size();
      for (auto item : msg.args) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time_limit
  {
    out << "time_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.time_limit, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.target.size() == 0) {
      out << "target: []\n";
    } else {
      out << "target:\n";
      for (auto item : msg.target) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: operation
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "operation: ";
    rosidl_generator_traits::value_to_yaml(msg.operation, out);
    out << "\n";
  }

  // member: args
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.args.size() == 0) {
      out << "args: []\n";
    } else {
      out << "args:\n";
      for (auto item : msg.args) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: time_limit
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_limit: ";
    rosidl_generator_traits::value_to_yaml(msg.time_limit, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_Goal & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_Goal>()
{
  return "action_interface::action::Cmd_Goal";
}

template<>
inline const char * name<action_interface::action::Cmd_Goal>()
{
  return "action_interface/action/Cmd_Goal";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface::action::Cmd_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: res
  {
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
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
  const Cmd_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
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

inline std::string to_yaml(const Cmd_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_Result & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_Result>()
{
  return "action_interface::action::Cmd_Result";
}

template<>
inline const char * name<action_interface::action::Cmd_Result>()
{
  return "action_interface/action/Cmd_Result";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<action_interface::action::Cmd_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: progress
  {
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: progress
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "progress: ";
    rosidl_generator_traits::value_to_yaml(msg.progress, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_Feedback & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_Feedback>()
{
  return "action_interface::action::Cmd_Feedback";
}

template<>
inline const char * name<action_interface::action::Cmd_Feedback>()
{
  return "action_interface/action/Cmd_Feedback";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<action_interface::action::Cmd_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "action_interface/action/detail/cmd__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_SendGoal_Request & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_SendGoal_Request>()
{
  return "action_interface::action::Cmd_SendGoal_Request";
}

template<>
inline const char * name<action_interface::action::Cmd_SendGoal_Request>()
{
  return "action_interface/action/Cmd_SendGoal_Request";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Cmd_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Cmd_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Cmd_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_SendGoal_Response & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_SendGoal_Response>()
{
  return "action_interface::action::Cmd_SendGoal_Response";
}

template<>
inline const char * name<action_interface::action::Cmd_SendGoal_Response>()
{
  return "action_interface/action/Cmd_SendGoal_Response";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<action_interface::action::Cmd_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface::action::Cmd_SendGoal>()
{
  return "action_interface::action::Cmd_SendGoal";
}

template<>
inline const char * name<action_interface::action::Cmd_SendGoal>()
{
  return "action_interface/action/Cmd_SendGoal";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface::action::Cmd_SendGoal_Request>::value &&
    has_fixed_size<action_interface::action::Cmd_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface::action::Cmd_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface::action::Cmd_SendGoal_Request>::value &&
    has_bounded_size<action_interface::action::Cmd_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<action_interface::action::Cmd_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface::action::Cmd_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface::action::Cmd_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_GetResult_Request & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_GetResult_Request>()
{
  return "action_interface::action::Cmd_GetResult_Request";
}

template<>
inline const char * name<action_interface::action::Cmd_GetResult_Request>()
{
  return "action_interface/action/Cmd_GetResult_Request";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Cmd_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface/action/detail/cmd__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_GetResult_Response & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_GetResult_Response>()
{
  return "action_interface::action::Cmd_GetResult_Response";
}

template<>
inline const char * name<action_interface::action::Cmd_GetResult_Response>()
{
  return "action_interface/action/Cmd_GetResult_Response";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Cmd_Result>::value> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Cmd_Result>::value> {};

template<>
struct is_message<action_interface::action::Cmd_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<action_interface::action::Cmd_GetResult>()
{
  return "action_interface::action::Cmd_GetResult";
}

template<>
inline const char * name<action_interface::action::Cmd_GetResult>()
{
  return "action_interface/action/Cmd_GetResult";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<action_interface::action::Cmd_GetResult_Request>::value &&
    has_fixed_size<action_interface::action::Cmd_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<action_interface::action::Cmd_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<action_interface::action::Cmd_GetResult_Request>::value &&
    has_bounded_size<action_interface::action::Cmd_GetResult_Response>::value
  >
{
};

template<>
struct is_service<action_interface::action::Cmd_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<action_interface::action::Cmd_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<action_interface::action::Cmd_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "action_interface/action/detail/cmd__traits.hpp"

namespace action_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Cmd_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Cmd_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Cmd_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace action_interface

namespace rosidl_generator_traits
{

[[deprecated("use action_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const action_interface::action::Cmd_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  action_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use action_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const action_interface::action::Cmd_FeedbackMessage & msg)
{
  return action_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<action_interface::action::Cmd_FeedbackMessage>()
{
  return "action_interface::action::Cmd_FeedbackMessage";
}

template<>
inline const char * name<action_interface::action::Cmd_FeedbackMessage>()
{
  return "action_interface/action/Cmd_FeedbackMessage";
}

template<>
struct has_fixed_size<action_interface::action::Cmd_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<action_interface::action::Cmd_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<action_interface::action::Cmd_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<action_interface::action::Cmd_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<action_interface::action::Cmd_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<action_interface::action::Cmd>
  : std::true_type
{
};

template<>
struct is_action_goal<action_interface::action::Cmd_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<action_interface::action::Cmd_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<action_interface::action::Cmd_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // ACTION_INTERFACE__ACTION__DETAIL__CMD__TRAITS_HPP_
