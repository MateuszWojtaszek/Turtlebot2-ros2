// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/DigitalOutput.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__DIGITAL_OUTPUT__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__DIGITAL_OUTPUT__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/digital_output__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::DigitalOutput & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: values
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.values.size() == 0) {
      out << "values: []\n";
    } else {
      out << "values:\n";
      for (auto item : msg.values) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.mask.size() == 0) {
      out << "mask: []\n";
    } else {
      out << "mask:\n";
      for (auto item : msg.mask) {
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

inline std::string to_yaml(const kobuki_ros_interfaces::msg::DigitalOutput & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::DigitalOutput>()
{
  return "kobuki_ros_interfaces::msg::DigitalOutput";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::DigitalOutput>()
{
  return "kobuki_ros_interfaces/msg/DigitalOutput";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::DigitalOutput>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::DigitalOutput>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::DigitalOutput>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__DIGITAL_OUTPUT__TRAITS_HPP_
