// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "action_interface/srv/detail/cmd__rosidl_typesupport_introspection_c.h"
#include "action_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "action_interface/srv/detail/cmd__functions.h"
#include "action_interface/srv/detail/cmd__struct.h"


// Include directives for member types
// Member `cmd`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interface__srv__Cmd_Request__init(message_memory);
}

void action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_fini_function(void * message_memory)
{
  action_interface__srv__Cmd_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_member_array[1] = {
  {
    "cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interface__srv__Cmd_Request, cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_members = {
  "action_interface__srv",  // message namespace
  "Cmd_Request",  // message name
  1,  // number of fields
  sizeof(action_interface__srv__Cmd_Request),
  action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_member_array,  // message members
  action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_type_support_handle = {
  0,
  &action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Request)() {
  if (!action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_type_support_handle.typesupport_identifier) {
    action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &action_interface__srv__Cmd_Request__rosidl_typesupport_introspection_c__Cmd_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "action_interface/srv/detail/cmd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "action_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "action_interface/srv/detail/cmd__functions.h"
// already included above
// #include "action_interface/srv/detail/cmd__struct.h"


// Include directives for member types
// Member `res_arg`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  action_interface__srv__Cmd_Response__init(message_memory);
}

void action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_fini_function(void * message_memory)
{
  action_interface__srv__Cmd_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_member_array[2] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interface__srv__Cmd_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "res_arg",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(action_interface__srv__Cmd_Response, res_arg),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_members = {
  "action_interface__srv",  // message namespace
  "Cmd_Response",  // message name
  2,  // number of fields
  sizeof(action_interface__srv__Cmd_Response),
  action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_member_array,  // message members
  action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_type_support_handle = {
  0,
  &action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Response)() {
  if (!action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_type_support_handle.typesupport_identifier) {
    action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &action_interface__srv__Cmd_Response__rosidl_typesupport_introspection_c__Cmd_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "action_interface/srv/detail/cmd__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_members = {
  "action_interface__srv",  // service namespace
  "Cmd",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_Request_message_type_support_handle,
  NULL  // response message
  // action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_Response_message_type_support_handle
};

static rosidl_service_type_support_t action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_type_support_handle = {
  0,
  &action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_action_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd)() {
  if (!action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_type_support_handle.typesupport_identifier) {
    action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Response)()->data;
  }

  return &action_interface__srv__detail__cmd__rosidl_typesupport_introspection_c__Cmd_service_type_support_handle;
}
