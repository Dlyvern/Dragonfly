#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "cw_main::cw_main__rosidl_typesupport_introspection_cpp" for configuration "Debug"
set_property(TARGET cw_main::cw_main__rosidl_typesupport_introspection_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(cw_main::cw_main__rosidl_typesupport_introspection_cpp PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libcw_main__rosidl_typesupport_introspection_cpp.so"
  IMPORTED_SONAME_DEBUG "libcw_main__rosidl_typesupport_introspection_cpp.so"
  )

list(APPEND _cmake_import_check_targets cw_main::cw_main__rosidl_typesupport_introspection_cpp )
list(APPEND _cmake_import_check_files_for_cw_main::cw_main__rosidl_typesupport_introspection_cpp "${_IMPORT_PREFIX}/lib/libcw_main__rosidl_typesupport_introspection_cpp.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)