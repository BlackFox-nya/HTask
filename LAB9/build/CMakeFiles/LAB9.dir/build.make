# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/blackfox/source/HTask/LAB9

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/blackfox/source/HTask/LAB9/build

# Include any dependencies generated for this target.
include CMakeFiles/LAB9.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/LAB9.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/LAB9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LAB9.dir/flags.make

CMakeFiles/LAB9.dir/codegen:
.PHONY : CMakeFiles/LAB9.dir/codegen

CMakeFiles/LAB9.dir/main.cpp.o: CMakeFiles/LAB9.dir/flags.make
CMakeFiles/LAB9.dir/main.cpp.o: /home/blackfox/source/HTask/LAB9/main.cpp
CMakeFiles/LAB9.dir/main.cpp.o: CMakeFiles/LAB9.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/blackfox/source/HTask/LAB9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LAB9.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/LAB9.dir/main.cpp.o -MF CMakeFiles/LAB9.dir/main.cpp.o.d -o CMakeFiles/LAB9.dir/main.cpp.o -c /home/blackfox/source/HTask/LAB9/main.cpp

CMakeFiles/LAB9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/LAB9.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/blackfox/source/HTask/LAB9/main.cpp > CMakeFiles/LAB9.dir/main.cpp.i

CMakeFiles/LAB9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/LAB9.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/blackfox/source/HTask/LAB9/main.cpp -o CMakeFiles/LAB9.dir/main.cpp.s

# Object files for target LAB9
LAB9_OBJECTS = \
"CMakeFiles/LAB9.dir/main.cpp.o"

# External object files for target LAB9
LAB9_EXTERNAL_OBJECTS =

LAB9: CMakeFiles/LAB9.dir/main.cpp.o
LAB9: CMakeFiles/LAB9.dir/build.make
LAB9: CMakeFiles/LAB9.dir/compiler_depend.ts
LAB9: CMakeFiles/LAB9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/blackfox/source/HTask/LAB9/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LAB9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LAB9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LAB9.dir/build: LAB9
.PHONY : CMakeFiles/LAB9.dir/build

CMakeFiles/LAB9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LAB9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LAB9.dir/clean

CMakeFiles/LAB9.dir/depend:
	cd /home/blackfox/source/HTask/LAB9/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/blackfox/source/HTask/LAB9 /home/blackfox/source/HTask/LAB9 /home/blackfox/source/HTask/LAB9/build /home/blackfox/source/HTask/LAB9/build /home/blackfox/source/HTask/LAB9/build/CMakeFiles/LAB9.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/LAB9.dir/depend

