# generated from rosidl_generator_py/resource/_idl.py.em
# with input from action_interface:srv/Cmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Cmd_Request(type):
    """Metaclass of message 'Cmd_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interface.srv.Cmd_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cmd__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cmd__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cmd__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cmd__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cmd__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Cmd_Request(metaclass=Metaclass_Cmd_Request):
    """Message class 'Cmd_Request'."""

    __slots__ = [
        '_cmd',
    ]

    _fields_and_field_types = {
        'cmd': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.cmd = kwargs.get('cmd', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.cmd != other.cmd:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def cmd(self):
        """Message field 'cmd'."""
        return self._cmd

    @cmd.setter
    def cmd(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'cmd' field must be of type 'str'"
        self._cmd = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_Cmd_Response(type):
    """Metaclass of message 'Cmd_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interface.srv.Cmd_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__cmd__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__cmd__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__cmd__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__cmd__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__cmd__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Cmd_Response(metaclass=Metaclass_Cmd_Response):
    """Message class 'Cmd_Response'."""

    __slots__ = [
        '_result',
        '_res_arg',
    ]

    _fields_and_field_types = {
        'result': 'boolean',
        'res_arg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.result = kwargs.get('result', bool())
        self.res_arg = kwargs.get('res_arg', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.result != other.result:
            return False
        if self.res_arg != other.res_arg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'result' field must be of type 'bool'"
        self._result = value

    @builtins.property
    def res_arg(self):
        """Message field 'res_arg'."""
        return self._res_arg

    @res_arg.setter
    def res_arg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'res_arg' field must be of type 'str'"
        self._res_arg = value


class Metaclass_Cmd(type):
    """Metaclass of service 'Cmd'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('action_interface')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'action_interface.srv.Cmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__cmd

            from action_interface.srv import _cmd
            if _cmd.Metaclass_Cmd_Request._TYPE_SUPPORT is None:
                _cmd.Metaclass_Cmd_Request.__import_type_support__()
            if _cmd.Metaclass_Cmd_Response._TYPE_SUPPORT is None:
                _cmd.Metaclass_Cmd_Response.__import_type_support__()


class Cmd(metaclass=Metaclass_Cmd):
    from action_interface.srv._cmd import Cmd_Request as Request
    from action_interface.srv._cmd import Cmd_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
