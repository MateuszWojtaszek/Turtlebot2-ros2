// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/DockInfraRed.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__DOCK_INFRA_RED__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__DOCK_INFRA_RED__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/dock_infra_red__struct.hpp"
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
  const kobuki_ros_interfaces::msg::DockInfraRed & msg,
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

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.data.size() == 0) {
      out << "data: []\n";
    } else {
      out << "data:\n";
      for (auto item : msg.data) {
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

inline std::string to_yaml(const kobuki_ros_interfaces::msg::DockInfraRed & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::DockInfraRed>()
{
  return "kobuki_ros_interfaces::msg::DockInfraRed";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::DockInfraRed>()
{
  return "kobuki_ros_interfaces/msg/DockInfraRed";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::DockInfraRed>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::DockInfraRed>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::DockInfraRed>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__DOCK_INFRA_RED__TRAITS_HPP_
