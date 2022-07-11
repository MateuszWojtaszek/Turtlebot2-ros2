// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kobuki_ros_interfaces:msg/BumperEvent.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kobuki_ros_interfaces/msg/detail/bumper_event__rosidl_typesupport_introspection_c.h"
#include "kobuki_ros_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kobuki_ros_interfaces/msg/detail/bumper_event__functions.h"
#include "kobuki_ros_interfaces/msg/detail/bumper_event__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kobuki_ros_interfaces__msg__BumperEvent__init(message_memory);
}

void BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_fini_function(void * message_memory)
{
  kobuki_ros_interfaces__msg__BumperEvent__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_member_array[2] = {
  {
    "bumper",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__BumperEvent, bumper),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kobuki_ros_interfaces__msg__BumperEvent, state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_members = {
  "kobuki_ros_interfaces__msg",  // message namespace
  "BumperEvent",  // message name
  2,  // number of fields
  sizeof(kobuki_ros_interfaces__msg__BumperEvent),
  BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_member_array,  // message members
  BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_init_function,  // function to initialize message memory (memory has to be allocated)
  BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_type_support_handle = {
  0,
  &BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kobuki_ros_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kobuki_ros_interfaces, msg, BumperEvent)() {
  if (!BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_type_support_handle.typesupport_identifier) {
    BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &BumperEvent__rosidl_typesupport_introspection_c__BumperEvent_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
