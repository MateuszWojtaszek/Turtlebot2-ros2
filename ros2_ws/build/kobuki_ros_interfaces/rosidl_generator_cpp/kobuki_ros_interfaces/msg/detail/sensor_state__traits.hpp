// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/SensorState.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/sensor_state__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::SensorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_yaml(msg.header, out, indentation + 2);
  }

  // member: time_stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time_stamp: ";
    value_to_yaml(msg.time_stamp, out);
    out << "\n";
  }

  // member: bumper
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bumper: ";
    value_to_yaml(msg.bumper, out);
    out << "\n";
  }

  // member: wheel_drop
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "wheel_drop: ";
    value_to_yaml(msg.wheel_drop, out);
    out << "\n";
  }

  // member: cliff
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cliff: ";
    value_to_yaml(msg.cliff, out);
    out << "\n";
  }

  // member: left_encoder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_encoder: ";
    value_to_yaml(msg.left_encoder, out);
    out << "\n";
  }

  // member: right_encoder
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_encoder: ";
    value_to_yaml(msg.right_encoder, out);
    out << "\n";
  }

  // member: left_pwm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "left_pwm: ";
    value_to_yaml(msg.left_pwm, out);
    out << "\n";
  }

  // member: right_pwm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "right_pwm: ";
    value_to_yaml(msg.right_pwm, out);
    out << "\n";
  }

  // member: buttons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "buttons: ";
    value_to_yaml(msg.buttons, out);
    out << "\n";
  }

  // member: charger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "charger: ";
    value_to_yaml(msg.charger, out);
    out << "\n";
  }

  // member: battery
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery: ";
    value_to_yaml(msg.battery, out);
    out << "\n";
  }

  // member: bottom
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.bottom.size() == 0) {
      out << "bottom: []\n";
    } else {
      out << "bottom:\n";
      for (auto item : msg.bottom) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current.size() == 0) {
      out << "current: []\n";
    } else {
      out << "current:\n";
      for (auto item : msg.current) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: over_current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "over_current: ";
    value_to_yaml(msg.over_current, out);
    out << "\n";
  }

  // member: digital_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "digital_input: ";
    value_to_yaml(msg.digital_input, out);
    out << "\n";
  }

  // member: analog_input
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.analog_input.size() == 0) {
      out << "analog_input: []\n";
    } else {
      out << "analog_input:\n";
      for (auto item : msg.analog_input) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const kobuki_ros_interfaces::msg::SensorState & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::SensorState>()
{
  return "kobuki_ros_interfaces::msg::SensorState";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::SensorState>()
{
  return "kobuki_ros_interfaces/msg/SensorState";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::SensorState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::SensorState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::SensorState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__SENSOR_STATE__TRAITS_HPP_
