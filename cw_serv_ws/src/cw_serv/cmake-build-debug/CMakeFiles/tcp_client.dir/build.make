# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/250/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /snap/clion/250/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tcp_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tcp_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tcp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tcp_client.dir/flags.make

CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o: CMakeFiles/tcp_client.dir/flags.make
CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o: tcp_client_autogen/mocs_compilation.cpp
CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o: CMakeFiles/tcp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o -MF CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/tcp_client_autogen/mocs_compilation.cpp

CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/tcp_client_autogen/mocs_compilation.cpp > CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.i

CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/tcp_client_autogen/mocs_compilation.cpp -o CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.s

CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o: CMakeFiles/tcp_client.dir/flags.make
CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp
CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o: CMakeFiles/tcp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o -MF CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o.d -o CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp

CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp > CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.i

CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp -o CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.s

# Object files for target tcp_client
tcp_client_OBJECTS = \
"CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o"

# External object files for target tcp_client
tcp_client_EXTERNAL_OBJECTS =

libtcp_client.a: CMakeFiles/tcp_client.dir/tcp_client_autogen/mocs_compilation.cpp.o
libtcp_client.a: CMakeFiles/tcp_client.dir/src/modules/ServerParts/TCPClient.cpp.o
libtcp_client.a: CMakeFiles/tcp_client.dir/build.make
libtcp_client.a: CMakeFiles/tcp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libtcp_client.a"
	$(CMAKE_COMMAND) -P CMakeFiles/tcp_client.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tcp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tcp_client.dir/build: libtcp_client.a
.PHONY : CMakeFiles/tcp_client.dir/build

CMakeFiles/tcp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tcp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tcp_client.dir/clean

CMakeFiles/tcp_client.dir/depend:
	cd /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/cmake-build-debug/CMakeFiles/tcp_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tcp_client.dir/depend

