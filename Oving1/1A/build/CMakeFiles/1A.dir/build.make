# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/debian/c++/Oving1/1A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/debian/c++/Oving1/1A/build

# Include any dependencies generated for this target.
include CMakeFiles/1A.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1A.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1A.dir/flags.make

CMakeFiles/1A.dir/Oving1A.cpp.o: CMakeFiles/1A.dir/flags.make
CMakeFiles/1A.dir/Oving1A.cpp.o: ../Oving1A.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/debian/c++/Oving1/1A/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/1A.dir/Oving1A.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/1A.dir/Oving1A.cpp.o -c /home/debian/c++/Oving1/1A/Oving1A.cpp

CMakeFiles/1A.dir/Oving1A.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1A.dir/Oving1A.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/debian/c++/Oving1/1A/Oving1A.cpp > CMakeFiles/1A.dir/Oving1A.cpp.i

CMakeFiles/1A.dir/Oving1A.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1A.dir/Oving1A.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/debian/c++/Oving1/1A/Oving1A.cpp -o CMakeFiles/1A.dir/Oving1A.cpp.s

CMakeFiles/1A.dir/Oving1A.cpp.o.requires:
.PHONY : CMakeFiles/1A.dir/Oving1A.cpp.o.requires

CMakeFiles/1A.dir/Oving1A.cpp.o.provides: CMakeFiles/1A.dir/Oving1A.cpp.o.requires
	$(MAKE) -f CMakeFiles/1A.dir/build.make CMakeFiles/1A.dir/Oving1A.cpp.o.provides.build
.PHONY : CMakeFiles/1A.dir/Oving1A.cpp.o.provides

CMakeFiles/1A.dir/Oving1A.cpp.o.provides.build: CMakeFiles/1A.dir/Oving1A.cpp.o

# Object files for target 1A
1A_OBJECTS = \
"CMakeFiles/1A.dir/Oving1A.cpp.o"

# External object files for target 1A
1A_EXTERNAL_OBJECTS =

1A: CMakeFiles/1A.dir/Oving1A.cpp.o
1A: CMakeFiles/1A.dir/build.make
1A: CMakeFiles/1A.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable 1A"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1A.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1A.dir/build: 1A
.PHONY : CMakeFiles/1A.dir/build

CMakeFiles/1A.dir/requires: CMakeFiles/1A.dir/Oving1A.cpp.o.requires
.PHONY : CMakeFiles/1A.dir/requires

CMakeFiles/1A.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1A.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1A.dir/clean

CMakeFiles/1A.dir/depend:
	cd /home/debian/c++/Oving1/1A/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/debian/c++/Oving1/1A /home/debian/c++/Oving1/1A /home/debian/c++/Oving1/1A/build /home/debian/c++/Oving1/1A/build /home/debian/c++/Oving1/1A/build/CMakeFiles/1A.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1A.dir/depend
