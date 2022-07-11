// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kobuki_ros_interfaces:msg/KeyboardInput.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__KEYBOARD_INPUT__STRUCT_H_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__KEYBOARD_INPUT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'KEYCODE_RIGHT'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_RIGHT = 67
};

/// Constant 'KEYCODE_LEFT'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_LEFT = 68
};

/// Constant 'KEYCODE_UP'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_UP = 65
};

/// Constant 'KEYCODE_DOWN'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_DOWN = 66
};

/// Constant 'KEYCODE_SPACE'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_SPACE = 32
};

/// Constant 'KEYCODE_ENABLE'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_ENABLE = 101
};

/// Constant 'KEYCODE_DISABLE'.
enum
{
  kobuki_ros_interfaces__msg__KeyboardInput__KEYCODE_DISABLE = 100
};

// Struct defined in msg/KeyboardInput in the package kobuki_ros_interfaces.
typedef struct kobuki_ros_interfaces__msg__KeyboardInput
{
  uint8_t pressed_key;
} kobuki_ros_interfaces__msg__KeyboardInput;

// Struct for a sequence of kobuki_ros_interfaces__msg__KeyboardInput.
typedef struct kobuki_ros_interfaces__msg__KeyboardInput__Sequence
{
  kobuki_ros_interfaces__msg__KeyboardInput * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kobuki_ros_interfaces__msg__KeyboardInput__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__KEYBOARD_INPUT__STRUCT_H_
