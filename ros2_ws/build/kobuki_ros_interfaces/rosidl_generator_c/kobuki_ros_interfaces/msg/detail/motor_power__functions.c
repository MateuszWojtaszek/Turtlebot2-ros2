// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kobuki_ros_interfaces:msg/MotorPower.idl
// generated code does not contain a copyright notice
#include "kobuki_ros_interfaces/msg/detail/motor_power__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


bool
kobuki_ros_interfaces__msg__MotorPower__init(kobuki_ros_interfaces__msg__MotorPower * msg)
{
  if (!msg) {
    return false;
  }
  // state
  return true;
}

void
kobuki_ros_interfaces__msg__MotorPower__fini(kobuki_ros_interfaces__msg__MotorPower * msg)
{
  if (!msg) {
    return;
  }
  // state
}

bool
kobuki_ros_interfaces__msg__MotorPower__are_equal(const kobuki_ros_interfaces__msg__MotorPower * lhs, const kobuki_ros_interfaces__msg__MotorPower * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  return true;
}

bool
kobuki_ros_interfaces__msg__MotorPower__copy(
  const kobuki_ros_interfaces__msg__MotorPower * input,
  kobuki_ros_interfaces__msg__MotorPower * output)
{
  if (!input || !output) {
    return false;
  }
  // state
  output->state = input->state;
  return true;
}

kobuki_ros_interfaces__msg__MotorPower *
kobuki_ros_interfaces__msg__MotorPower__create()
{
  kobuki_ros_interfaces__msg__MotorPower * msg = (kobuki_ros_interfaces__msg__MotorPower *)malloc(sizeof(kobuki_ros_interfaces__msg__MotorPower));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kobuki_ros_interfaces__msg__MotorPower));
  bool success = kobuki_ros_interfaces__msg__MotorPower__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
kobuki_ros_interfaces__msg__MotorPower__destroy(kobuki_ros_interfaces__msg__MotorPower * msg)
{
  if (msg) {
    kobuki_ros_interfaces__msg__MotorPower__fini(msg);
  }
  free(msg);
}


bool
kobuki_ros_interfaces__msg__MotorPower__Sequence__init(kobuki_ros_interfaces__msg__MotorPower__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  kobuki_ros_interfaces__msg__MotorPower * data = NULL;
  if (size) {
    data = (kobuki_ros_interfaces__msg__MotorPower *)calloc(size, sizeof(kobuki_ros_interfaces__msg__MotorPower));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kobuki_ros_interfaces__msg__MotorPower__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kobuki_ros_interfaces__msg__MotorPower__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
kobuki_ros_interfaces__msg__MotorPower__Sequence__fini(kobuki_ros_interfaces__msg__MotorPower__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      kobuki_ros_interfaces__msg__MotorPower__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

kobuki_ros_interfaces__msg__MotorPower__Sequence *
kobuki_ros_interfaces__msg__MotorPower__Sequence__create(size_t size)
{
  kobuki_ros_interfaces__msg__MotorPower__Sequence * array = (kobuki_ros_interfaces__msg__MotorPower__Sequence *)malloc(sizeof(kobuki_ros_interfaces__msg__MotorPower__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = kobuki_ros_interfaces__msg__MotorPower__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
kobuki_ros_interfaces__msg__MotorPower__Sequence__destroy(kobuki_ros_interfaces__msg__MotorPower__Sequence * array)
{
  if (array) {
    kobuki_ros_interfaces__msg__MotorPower__Sequence__fini(array);
  }
  free(array);
}

bool
kobuki_ros_interfaces__msg__MotorPower__Sequence__are_equal(const kobuki_ros_interfaces__msg__MotorPower__Sequence * lhs, const kobuki_ros_interfaces__msg__MotorPower__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kobuki_ros_interfaces__msg__MotorPower__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kobuki_ros_interfaces__msg__MotorPower__Sequence__copy(
  const kobuki_ros_interfaces__msg__MotorPower__Sequence * input,
  kobuki_ros_interfaces__msg__MotorPower__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kobuki_ros_interfaces__msg__MotorPower);
    kobuki_ros_interfaces__msg__MotorPower * data =
      (kobuki_ros_interfaces__msg__MotorPower *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kobuki_ros_interfaces__msg__MotorPower__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          kobuki_ros_interfaces__msg__MotorPower__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kobuki_ros_interfaces__msg__MotorPower__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
