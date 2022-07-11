// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kobuki_ros_interfaces:msg/VersionInfo.idl
// generated code does not contain a copyright notice

#ifndef KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__TRAITS_HPP_
#define KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__TRAITS_HPP_

#include "kobuki_ros_interfaces/msg/detail/version_info__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const kobuki_ros_interfaces::msg::VersionInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: hardware
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "hardware: ";
    value_to_yaml(msg.hardware, out);
    out << "\n";
  }

  // member: firmware
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "firmware: ";
    value_to_yaml(msg.firmware, out);
    out << "\n";
  }

  // member: software
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "software: ";
    value_to_yaml(msg.software, out);
    out << "\n";
  }

  // member: udid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.udid.size() == 0) {
      out << "udid: []\n";
    } else {
      out << "udid:\n";
      for (auto item : msg.udid) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: features
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "features: ";
    value_to_yaml(msg.features, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const kobuki_ros_interfaces::msg::VersionInfo & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<kobuki_ros_interfaces::msg::VersionInfo>()
{
  return "kobuki_ros_interfaces::msg::VersionInfo";
}

template<>
inline const char * name<kobuki_ros_interfaces::msg::VersionInfo>()
{
  return "kobuki_ros_interfaces/msg/VersionInfo";
}

template<>
struct has_fixed_size<kobuki_ros_interfaces::msg::VersionInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<kobuki_ros_interfaces::msg::VersionInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<kobuki_ros_interfaces::msg::VersionInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KOBUKI_ROS_INTERFACES__MSG__DETAIL__VERSION_INFO__TRAITS_HPP_
