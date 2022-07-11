// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kobuki_ros_interfaces:msg/SensorState.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__STRUCT_H_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'BUMPER_RIGHT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUMPER_RIGHT = 1
};

/// Constant 'BUMPER_CENTRE'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUMPER_CENTRE = 2
};

/// Constant 'BUMPER_LEFT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUMPER_LEFT = 4
};

/// Constant 'WHEEL_DROP_RIGHT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__WHEEL_DROP_RIGHT = 1
};

/// Constant 'WHEEL_DROP_LEFT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__WHEEL_DROP_LEFT = 2
};

/// Constant 'CLIFF_RIGHT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__CLIFF_RIGHT = 1
};

/// Constant 'CLIFF_CENTRE'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__CLIFF_CENTRE = 2
};

/// Constant 'CLIFF_LEFT'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__CLIFF_LEFT = 4
};

/// Constant 'BUTTON0'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUTTON0 = 1
};

/// Constant 'BUTTON1'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUTTON1 = 2
};

/// Constant 'BUTTON2'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__BUTTON2 = 4
};

/// Constant 'DISCHARGING'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DISCHARGING = 0
};

/// Constant 'DOCKING_CHARGED'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DOCKING_CHARGED = 2
};

/// Constant 'DOCKING_CHARGING'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DOCKING_CHARGING = 6
};

/// Constant 'ADAPTER_CHARGED'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__ADAPTER_CHARGED = 18
};

/// Constant 'ADAPTER_CHARGING'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__ADAPTER_CHARGING = 22
};

/// Constant 'OVER_CURRENT_LEFT_WHEEL'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__OVER_CURRENT_LEFT_WHEEL = 1
};

/// Constant 'OVER_CURRENT_RIGHT_WHEEL'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__OVER_CURRENT_RIGHT_WHEEL = 2
};

/// Constant 'OVER_CURRENT_BOTH_WHEELS'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__OVER_CURRENT_BOTH_WHEELS = 3
};

/// Constant 'DIGITAL_INPUT0'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DIGITAL_INPUT0 = 1
};

/// Constant 'DIGITAL_INPUT1'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DIGITAL_INPUT1 = 2
};

/// Constant 'DIGITAL_INPUT2'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DIGITAL_INPUT2 = 4
};

/// Constant 'DIGITAL_INPUT3'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DIGITAL_INPUT3 = 8
};

/// Constant 'DB25_TEST_BOARD_CONNECTED'.
enum
{
  kobuki_ros_interfaces__msg__SensorState__DB25_TEST_BOARD_CONNECTED = 64
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'bottom'
// Member 'current'
// Member 'analog_input'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/SensorState in the package kobuki_ros_interfaces.
typedef struct kobuki_ros_interfaces__msg__SensorState
{
  std_msgs__msg__Header header;
  uint16_t time_stamp;
  uint8_t bumper;
  uint8_t wheel_drop;
  uint8_t cliff;
  uint16_t left_encoder;
  uint16_t right_encoder;
  int8_t left_pwm;
  int8_t right_pwm;
  uint8_t buttons;
  uint8_t charger;
  uint8_t battery;
  rosidl_runtime_c__uint16__Sequence bottom;
  rosidl_runtime_c__uint8__Sequence current;
  uint8_t over_current;
  uint16_t digital_input;
  rosidl_runtime_c__uint16__Sequence analog_input;
} kobuki_ros_interfaces__msg__SensorState;

// Struct for a sequence of kobuki_ros_interfaces__msg__SensorState.
typedef struct kobuki_ros_interfaces__msg__SensorState__Sequence
{
  kobuki_ros_interfaces__msg__SensorState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kobuki_ros_interfaces__msg__SensorState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__STRUCT_H_
