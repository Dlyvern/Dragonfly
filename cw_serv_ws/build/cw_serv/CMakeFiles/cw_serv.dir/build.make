# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv

# Include any dependencies generated for this target.
include CMakeFiles/cw_serv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cw_serv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cw_serv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cw_serv.dir/flags.make

CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o: cw_serv_autogen/mocs_compilation.cpp
CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o -MF CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/cw_serv_autogen/mocs_compilation.cpp

CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/cw_serv_autogen/mocs_compilation.cpp > CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.i

CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/cw_serv_autogen/mocs_compilation.cpp -o CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.s

CMakeFiles/cw_serv.dir/src/main.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/main.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/main.cpp
CMakeFiles/cw_serv.dir/src/main.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cw_serv.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/main.cpp.o -MF CMakeFiles/cw_serv.dir/src/main.cpp.o.d -o CMakeFiles/cw_serv.dir/src/main.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/main.cpp

CMakeFiles/cw_serv.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/main.cpp > CMakeFiles/cw_serv.dir/src/main.cpp.i

CMakeFiles/cw_serv.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/main.cpp -o CMakeFiles/cw_serv.dir/src/main.cpp.s

CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionClient.cpp
CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o -MF CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o.d -o CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionClient.cpp

CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionClient.cpp > CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.i

CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionClient.cpp -o CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.s

CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionServer.cpp
CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o -MF CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o.d -o CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionServer.cpp

CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionServer.cpp > CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.i

CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/actions/ActionServer.cpp -o CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.s

CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/cw_structs/Command.cpp
CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o -MF CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o.d -o CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/cw_structs/Command.cpp

CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/cw_structs/Command.cpp > CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.i

CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/cw_structs/Command.cpp -o CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.s

CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Logger.cpp
CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Logger.cpp

CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Logger.cpp > CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.i

CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Logger.cpp -o CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.s

CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Module.cpp
CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Module.cpp

CMakeFiles/cw_serv.dir/src/modules/Module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/Module.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Module.cpp > CMakeFiles/cw_serv.dir/src/modules/Module.cpp.i

CMakeFiles/cw_serv.dir/src/modules/Module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/Module.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/Module.cpp -o CMakeFiles/cw_serv.dir/src/modules/Module.cpp.s

CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/TCPServer.cpp
CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/TCPServer.cpp

CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/TCPServer.cpp > CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.i

CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/TCPServer.cpp -o CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.s

CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/ClientManager.cpp
CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/ClientManager.cpp

CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/ClientManager.cpp > CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.i

CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/ClientManager.cpp -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.s

CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/Packet.cpp
CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/Packet.cpp

CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/Packet.cpp > CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.i

CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/Packet.cpp -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.s

CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o: CMakeFiles/cw_serv.dir/flags.make
CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp
CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o: CMakeFiles/cw_serv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o -MF CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o.d -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o -c /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp

CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp > CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.i

CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv/src/modules/ServerParts/TCPClient.cpp -o CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.s

# Object files for target cw_serv
cw_serv_OBJECTS = \
"CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/cw_serv.dir/src/main.cpp.o" \
"CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o" \
"CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o" \
"CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o" \
"CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o"

# External object files for target cw_serv
cw_serv_EXTERNAL_OBJECTS =

cw_serv: CMakeFiles/cw_serv.dir/cw_serv_autogen/mocs_compilation.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/main.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/actions/ActionClient.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/actions/ActionServer.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/cw_structs/Command.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/Logger.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/Module.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/TCPServer.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/ServerParts/ClientManager.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/ServerParts/Packet.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/src/modules/ServerParts/TCPClient.cpp.o
cw_serv: CMakeFiles/cw_serv.dir/build.make
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/librclcpp_action.so
cw_serv: /opt/ros/humble/lib/libcomponent_manager.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_fastrtps_c.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_introspection_c.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_introspection_cpp.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_cpp.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_generator_py.so
cw_serv: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
cw_serv: /usr/lib/x86_64-linux-gnu/libQt5Network.so.5.15.3
cw_serv: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.74.0
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libstd_msgs__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/librcl_action.so
cw_serv: /opt/ros/humble/lib/librclcpp.so
cw_serv: /opt/ros/humble/lib/liblibstatistics_collector.so
cw_serv: /opt/ros/humble/lib/librcl.so
cw_serv: /opt/ros/humble/lib/librmw_implementation.so
cw_serv: /opt/ros/humble/lib/librcl_logging_spdlog.so
cw_serv: /opt/ros/humble/lib/librcl_logging_interface.so
cw_serv: /opt/ros/humble/lib/librcl_yaml_param_parser.so
cw_serv: /opt/ros/humble/lib/libyaml.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/librosgraph_msgs__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libstatistics_msgs__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libtracetools.so
cw_serv: /opt/ros/humble/lib/libament_index_cpp.so
cw_serv: /opt/ros/humble/lib/libclass_loader.so
cw_serv: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.1.0
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libcomposition_interfaces__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/librcl_interfaces__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_fastrtps_cpp.so
cw_serv: /opt/ros/humble/lib/libfastcdr.so.1.0.24
cw_serv: /opt/ros/humble/lib/librmw.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_introspection_cpp.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_introspection_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_cpp.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_cpp.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_typesupport_c.so
cw_serv: /home/dlyvern/Projects/Dragonfly/cw_serv_ws/install/action_interface/lib/libaction_interface__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_py.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libaction_msgs__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libbuiltin_interfaces__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_generator_py.so
cw_serv: /usr/lib/x86_64-linux-gnu/libpython3.10.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/libunique_identifier_msgs__rosidl_generator_c.so
cw_serv: /opt/ros/humble/lib/librosidl_typesupport_c.so
cw_serv: /opt/ros/humble/lib/librcpputils.so
cw_serv: /opt/ros/humble/lib/librosidl_runtime_c.so
cw_serv: /opt/ros/humble/lib/librcutils.so
cw_serv: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
cw_serv: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
cw_serv: CMakeFiles/cw_serv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable cw_serv"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cw_serv.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cw_serv.dir/build: cw_serv
.PHONY : CMakeFiles/cw_serv.dir/build

CMakeFiles/cw_serv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cw_serv.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cw_serv.dir/clean

CMakeFiles/cw_serv.dir/depend:
	cd /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/src/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv /home/dlyvern/Projects/Dragonfly/cw_serv_ws/build/cw_serv/CMakeFiles/cw_serv.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cw_serv.dir/depend

