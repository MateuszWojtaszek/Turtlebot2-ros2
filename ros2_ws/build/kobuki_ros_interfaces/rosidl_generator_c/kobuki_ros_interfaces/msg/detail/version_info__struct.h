// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kobuki_ros_interfaces:msg/VersionInfo.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__STRUCT_H_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SMOOTH_MOVE_START'.
enum
{
  kobuki_ros_interfaces__msg__VersionInfo__SMOOTH_MOVE_START = 1ull
};

/// Constant 'GYROSCOPE_3D_DATA'.
enum
{
  kobuki_ros_interfaces__msg__VersionInfo__GYROSCOPE_3D_DATA = 2ull
};

// Include directives for member types
// Member 'hardware'
// Member 'firmware'
// Member 'software'
#include "rosidl_runtime_c/string.h"
// Member 'udid'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/VersionInfo in the package kobuki_ros_interfaces.
typedef struct kobuki_ros_interfaces__msg__VersionInfo
{
  rosidl_runtime_c__String hardware;
  rosidl_runtime_c__String firmware;
  rosidl_runtime_c__String software;
  rosidl_runtime_c__uint32__Sequence udid;
  uint64_t features;
} kobuki_ros_interfaces__msg__VersionInfo;

// Struct for a sequence of kobuki_ros_interfaces__msg__VersionInfo.
typedef struct kobuki_ros_interfaces__msg__VersionInfo__Sequence
{
  kobuki_ros_interfaces__msg__VersionInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kobuki_ros_interfaces__msg__VersionInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__STRUCT_H_
