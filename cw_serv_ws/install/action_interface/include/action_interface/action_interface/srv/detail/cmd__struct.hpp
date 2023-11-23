// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from action_interface:srv/Cmd.idl
// generated code does not contain a copyright notice

#ifndef ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_HPP_
#define ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__action_interface__srv__Cmd_Request __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__srv__Cmd_Request __declspec(deprecated)
#endif

namespace action_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Cmd_Request_
{
  using Type = Cmd_Request_<ContainerAllocator>;

  explicit Cmd_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = "";
    }
  }

  explicit Cmd_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : cmd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cmd = "";
    }
  }

  // field types and members
  using _cmd_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _cmd_type cmd;

  // setters for named parameter idiom
  Type & set__cmd(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->cmd = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::srv::Cmd_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::srv::Cmd_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::srv::Cmd_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::srv::Cmd_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__srv__Cmd_Request
    std::shared_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__srv__Cmd_Request
    std::shared_ptr<action_interface::srv::Cmd_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cmd_Request_ & other) const
  {
    if (this->cmd != other.cmd) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cmd_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cmd_Request_

// alias to use template instance with default allocator
using Cmd_Request =
  action_interface::srv::Cmd_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_interface


#ifndef _WIN32
# define DEPRECATED__action_interface__srv__Cmd_Response __attribute__((deprecated))
#else
# define DEPRECATED__action_interface__srv__Cmd_Response __declspec(deprecated)
#endif

namespace action_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Cmd_Response_
{
  using Type = Cmd_Response_<ContainerAllocator>;

  explicit Cmd_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->res_arg = "";
    }
  }

  explicit Cmd_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : res_arg(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
      this->res_arg = "";
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;
  using _res_arg_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _res_arg_type res_arg;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }
  Type & set__res_arg(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->res_arg = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    action_interface::srv::Cmd_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const action_interface::srv::Cmd_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      action_interface::srv::Cmd_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      action_interface::srv::Cmd_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__action_interface__srv__Cmd_Response
    std::shared_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__action_interface__srv__Cmd_Response
    std::shared_ptr<action_interface::srv::Cmd_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Cmd_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    if (this->res_arg != other.res_arg) {
      return false;
    }
    return true;
  }
  bool operator!=(const Cmd_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Cmd_Response_

// alias to use template instance with default allocator
using Cmd_Response =
  action_interface::srv::Cmd_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace action_interface

namespace action_interface
{

namespace srv
{

struct Cmd
{
  using Request = action_interface::srv::Cmd_Request;
  using Response = action_interface::srv::Cmd_Response;
};

}  // namespace srv

}  // namespace action_interface

#endif  // ACTION_INTERFACE__SRV__DETAIL__CMD__STRUCT_HPP_
