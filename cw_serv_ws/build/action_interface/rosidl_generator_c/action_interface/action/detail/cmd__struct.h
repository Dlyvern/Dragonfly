// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from action_interface:action/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__ACTION__DETAIL__CMD__STRUCT_H_
#define ACTION_INTERFACE__ACTION__DETAIL__CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target'
// Member 'operation'
// Member 'args'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_Goal
{
  rosidl_runtime_c__String__Sequence target;
  rosidl_runtime_c__String operation;
  rosidl_runtime_c__String__Sequence args;
  int32_t time_limit;
} action_interface__action__Cmd_Goal;

// Struct for a sequence of action_interface__action__Cmd_Goal.
typedef struct action_interface__action__Cmd_Goal__Sequence
{
  action_interface__action__Cmd_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'res_arg'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_Result
{
  bool res;
  rosidl_runtime_c__String res_arg;
} action_interface__action__Cmd_Result;

// Struct for a sequence of action_interface__action__Cmd_Result.
typedef struct action_interface__action__Cmd_Result__Sequence
{
  action_interface__action__Cmd_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_Feedback
{
  int32_t progress;
} action_interface__action__Cmd_Feedback;

// Struct for a sequence of action_interface__action__Cmd_Feedback.
typedef struct action_interface__action__Cmd_Feedback__Sequence
{
  action_interface__action__Cmd_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "action_interface/action/detail/cmd__struct.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interface__action__Cmd_Goal goal;
} action_interface__action__Cmd_SendGoal_Request;

// Struct for a sequence of action_interface__action__Cmd_SendGoal_Request.
typedef struct action_interface__action__Cmd_SendGoal_Request__Sequence
{
  action_interface__action__Cmd_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} action_interface__action__Cmd_SendGoal_Response;

// Struct for a sequence of action_interface__action__Cmd_SendGoal_Response.
typedef struct action_interface__action__Cmd_SendGoal_Response__Sequence
{
  action_interface__action__Cmd_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} action_interface__action__Cmd_GetResult_Request;

// Struct for a sequence of action_interface__action__Cmd_GetResult_Request.
typedef struct action_interface__action__Cmd_GetResult_Request__Sequence
{
  action_interface__action__Cmd_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "action_interface/action/detail/cmd__struct.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_GetResult_Response
{
  int8_t status;
  action_interface__action__Cmd_Result result;
} action_interface__action__Cmd_GetResult_Response;

// Struct for a sequence of action_interface__action__Cmd_GetResult_Response.
typedef struct action_interface__action__Cmd_GetResult_Response__Sequence
{
  action_interface__action__Cmd_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "action_interface/action/detail/cmd__struct.h"

/// Struct defined in action/Cmd in the package action_interface.
typedef struct action_interface__action__Cmd_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  action_interface__action__Cmd_Feedback feedback;
} action_interface__action__Cmd_FeedbackMessage;

// Struct for a sequence of action_interface__action__Cmd_FeedbackMessage.
typedef struct action_interface__action__Cmd_FeedbackMessage__Sequence
{
  action_interface__action__Cmd_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} action_interface__action__Cmd_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ACTION_INTERFACE__ACTION__DETAIL__CMD__STRUCT_H_
