// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kobuki_ros_interfaces:msg/ControllerInfo.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__STRUCT_H_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DEFAULT'.
enum
{
  kobuki_ros_interfaces__msg__ControllerInfo__DEFAULT = 0
};

/// Constant 'USER_CONFIGURED'.
enum
{
  kobuki_ros_interfaces__msg__ControllerInfo__USER_CONFIGURED = 1
};

// Struct defined in msg/ControllerInfo in the package kobuki_ros_interfaces.
typedef struct kobuki_ros_interfaces__msg__ControllerInfo
{
  uint8_t type;
  double p_gain;
  double i_gain;
  double d_gain;
} kobuki_ros_interfaces__msg__ControllerInfo;

// Struct for a sequence of kobuki_ros_interfaces__msg__ControllerInfo.
typedef struct kobuki_ros_interfaces__msg__ControllerInfo__Sequence
{
  kobuki_ros_interfaces__msg__ControllerInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kobuki_ros_interfaces__msg__ControllerInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__STRUCT_H_
