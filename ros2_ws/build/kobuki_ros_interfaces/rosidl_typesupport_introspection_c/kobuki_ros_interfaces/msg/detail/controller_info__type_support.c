// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kobuki_ros_interfaces:msg/ControllerInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kobuki_ros_interfaces/msg/detail/controller_info__rosidl_typesupport_introspection_c.h"
#include "kobuki_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kobuki_ros_interfaces/msg/detail/controller_info__functions.h"
#include "kobuki_ros_interfaces/msg/detail/controller_info__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kobuki_ros_interfaces__msg__ControllerInfo__init(message_memory);
}

void ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_fini_function(void * message_memory)
{
  kobuki_ros_interfaces__msg__ControllerInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_member_array[4] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__ControllerInfo, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "p_gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__ControllerInfo, p_gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "i_gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__ControllerInfo, i_gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "d_gain",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__ControllerInfo, d_gain),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_members = {
  "kobuki_ros_interfaces__msg",  // message namespace
  "ControllerInfo",  // message name
  4,  // number of fields
  sizeof(kobuki_ros_interfaces__msg__ControllerInfo),
  ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_member_array,  // message members
  ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_type_support_handle = {
  0,
  &ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kobuki_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kobuki_ros_interfaces, msg, ControllerInfo)() {
  if (!ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_type_support_handle.typesupport_identifier) {
    ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ControllerInfo__rosidl_typesupport_introspection_c__ControllerInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif