// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/Led.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__LED__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__LED__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/led__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::Led & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value: ";
    value_to_yaml(msg.value, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const kobuki_ros_interfaces::msg::Led & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::Led>()
{
  return "kobuki_ros_interfaces::msg::Led";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::Led>()
{
  return "kobuki_ros_interfaces/msg/Led";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::Led>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::Led>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::Led>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__LED__TRAITS_HPP_
