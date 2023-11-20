# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_cw_serv_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED cw_serv_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(cw_serv_FOUND FALSE)
  elseif(NOT cw_serv_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(cw_serv_FOUND FALSE)
  endif()
  return()
endif()
set(_cw_serv_CONFIG_INCLUDED TRUE)

# output package information
if(NOT cw_serv_FIND_QUIETLY)
  message(STATUS "Found cw_serv: 0.0.0 (${cw_serv_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'cw_serv' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${cw_serv_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(cw_serv_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "CMakeConfix.cmake")
foreach(_extra ${_extras})
  include("${cw_serv_DIR}/${_extra}")
endforeach()
