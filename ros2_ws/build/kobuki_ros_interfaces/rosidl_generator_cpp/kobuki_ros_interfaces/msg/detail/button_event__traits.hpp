// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/ButtonEvent.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__BUTTON_EVENT__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__BUTTON_EVENT__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/button_event__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::ButtonEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: button
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "button: ";
    value_to_yaml(msg.button, out);
    out << "\n";
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    value_to_yaml(msg.state, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const kobuki_ros_interfaces::msg::ButtonEvent & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::ButtonEvent>()
{
  return "kobuki_ros_interfaces::msg::ButtonEvent";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::ButtonEvent>()
{
  return "kobuki_ros_interfaces/msg/ButtonEvent";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::ButtonEvent>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::ButtonEvent>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::ButtonEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__BUTTON_EVENT__TRAITS_HPP_
