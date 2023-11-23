// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "action_interface/srv/detail/cmd__struct.h"
#include "action_interface/srv/detail/cmd__type_support.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Cmd_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Cmd_Request_type_support_ids_t;

static const _Cmd_Request_type_support_ids_t _Cmd_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Cmd_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Cmd_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Cmd_Request_type_support_symbol_names_t _Cmd_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interface, srv, Cmd_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Request)),
  }
};

typedef struct _Cmd_Request_type_support_data_t
{
  void * data[2];
} _Cmd_Request_type_support_data_t;

static _Cmd_Request_type_support_data_t _Cmd_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Cmd_Request_message_typesupport_map = {
  2,
  "action_interface",
  &_Cmd_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Cmd_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Cmd_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Cmd_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Cmd_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace action_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, action_interface, srv, Cmd_Request)() {
  return &::action_interface::srv::rosidl_typesupport_c::Cmd_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "action_interface/srv/detail/cmd__struct.h"
// already included above
// #include "action_interface/srv/detail/cmd__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Cmd_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Cmd_Response_type_support_ids_t;

static const _Cmd_Response_type_support_ids_t _Cmd_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Cmd_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Cmd_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Cmd_Response_type_support_symbol_names_t _Cmd_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interface, srv, Cmd_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd_Response)),
  }
};

typedef struct _Cmd_Response_type_support_data_t
{
  void * data[2];
} _Cmd_Response_type_support_data_t;

static _Cmd_Response_type_support_data_t _Cmd_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Cmd_Response_message_typesupport_map = {
  2,
  "action_interface",
  &_Cmd_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Cmd_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Cmd_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Cmd_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Cmd_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace action_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, action_interface, srv, Cmd_Response)() {
  return &::action_interface::srv::rosidl_typesupport_c::Cmd_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "action_interface/srv/detail/cmd__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace action_interface
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _Cmd_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Cmd_type_support_ids_t;

static const _Cmd_type_support_ids_t _Cmd_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _Cmd_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Cmd_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Cmd_type_support_symbol_names_t _Cmd_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, action_interface, srv, Cmd)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, action_interface, srv, Cmd)),
  }
};

typedef struct _Cmd_type_support_data_t
{
  void * data[2];
} _Cmd_type_support_data_t;

static _Cmd_type_support_data_t _Cmd_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Cmd_service_typesupport_map = {
  2,
  "action_interface",
  &_Cmd_service_typesupport_ids.typesupport_identifier[0],
  &_Cmd_service_typesupport_symbol_names.symbol_name[0],
  &_Cmd_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Cmd_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Cmd_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace action_interface

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, action_interface, srv, Cmd)() {
  return &::action_interface::srv::rosidl_typesupport_c::Cmd_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
