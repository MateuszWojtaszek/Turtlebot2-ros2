// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/ControllerInfo.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/controller_info__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::ControllerInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: p_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_gain: ";
    value_to_yaml(msg.p_gain, out);
    out << "\n";
  }

  // member: i_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "i_gain: ";
    value_to_yaml(msg.i_gain, out);
    out << "\n";
  }

  // member: d_gain
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "d_gain: ";
    value_to_yaml(msg.d_gain, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const kobuki_ros_interfaces::msg::ControllerInfo & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::ControllerInfo>()
{
  return "kobuki_ros_interfaces::msg::ControllerInfo";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::ControllerInfo>()
{
  return "kobuki_ros_interfaces/msg/ControllerInfo";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::ControllerInfo>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::ControllerInfo>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::ControllerInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__CONTROLLER_INFO__TRAITS_HPP_
