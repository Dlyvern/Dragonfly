// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_H_
#define ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'cmd'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Cmd in the package action_interface.
typedef struct action_interface__srv__Cmd_Request
{
  rosidl_runtime_c__String cmd;
} action_interface__srv__Cmd_Request;

// Struct for a sequence of action_interface__srv__Cmd_Request.
typedef struct action_interface__srv__Cmd_Request__Sequence
{
  action_interface__srv__Cmd_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__srv__Cmd_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'res_arg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Cmd in the package action_interface.
typedef struct action_interface__srv__Cmd_Response
{
  bool result;
  rosidl_runtime_c__String res_arg;
} action_interface__srv__Cmd_Response;

// Struct for a sequence of action_interface__srv__Cmd_Response.
typedef struct action_interface__srv__Cmd_Response__Sequence
{
  action_interface__srv__Cmd_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__srv__Cmd_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_H_
