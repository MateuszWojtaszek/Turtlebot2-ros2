// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kobuki_ros_interfaces:msg/WheelDropEvent.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__WHEEL_DROP_EVENT__STRUCT_H_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__WHEEL_DROP_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'LEFT'.
enum
{
  kobuki_ros_interfaces__msg__WheelDropEvent__LEFT = 0
};

/// Constant 'RIGHT'.
enum
{
  kobuki_ros_interfaces__msg__WheelDropEvent__RIGHT = 1
};

/// Constant 'RAISED'.
enum
{
  kobuki_ros_interfaces__msg__WheelDropEvent__RAISED = 0
};

/// Constant 'DROPPED'.
enum
{
  kobuki_ros_interfaces__msg__WheelDropEvent__DROPPED = 1
};

// Struct defined in msg/WheelDropEvent in the package kobuki_ros_interfaces.
typedef struct kobuki_ros_interfaces__msg__WheelDropEvent
{
  uint8_t wheel;
  uint8_t state;
} kobuki_ros_interfaces__msg__WheelDropEvent;

// Struct for a sequence of kobuki_ros_interfaces__msg__WheelDropEvent.
typedef struct kobuki_ros_interfaces__msg__WheelDropEvent__Sequence
{
  kobuki_ros_interfaces__msg__WheelDropEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kobuki_ros_interfaces__msg__WheelDropEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__WHEEL_DROP_EVENT__STRUCT_H_
