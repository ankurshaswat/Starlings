# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/ankurshaswat/MyFiles/Repos/Starlings/Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build

# Include any dependencies generated for this target.
include ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/depend.make

# Include the progress variables for this target.
include ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/progress.make

# Include the compile flags for this target's objects.
include ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/flags.make

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/flags.make
../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o: ../external/glfw-3.1.2/tests/cursor.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o"
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cursor.dir/cursor.c.o   -c /home/ankurshaswat/MyFiles/Repos/Starlings/Code/external/glfw-3.1.2/tests/cursor.c

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cursor.dir/cursor.c.i"
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ankurshaswat/MyFiles/Repos/Starlings/Code/external/glfw-3.1.2/tests/cursor.c > CMakeFiles/cursor.dir/cursor.c.i

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cursor.dir/cursor.c.s"
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ankurshaswat/MyFiles/Repos/Starlings/Code/external/glfw-3.1.2/tests/cursor.c -o CMakeFiles/cursor.dir/cursor.c.s

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.requires:

.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.requires

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.provides: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.requires
	$(MAKE) -f ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build.make ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.provides.build
.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.provides

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.provides.build: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o


# Object files for target cursor
cursor_OBJECTS = \
"CMakeFiles/cursor.dir/cursor.c.o"

# External object files for target cursor
cursor_EXTERNAL_OBJECTS =

../bin/cursor: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o
../bin/cursor: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build.make
../bin/cursor: ../bin/external/glfw-3.1.2/src/libglfw3.a
../bin/cursor: /usr/lib/x86_64-linux-gnu/librt.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libm.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libXrandr.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libXinerama.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libXi.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libXcursor.so
../bin/cursor: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/cursor: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../../cursor"
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cursor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build: ../bin/cursor

.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/build

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/requires: ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/cursor.c.o.requires

.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/requires

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/clean:
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/cursor.dir/cmake_clean.cmake
.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/clean

../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/depend:
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ankurshaswat/MyFiles/Repos/Starlings/Code /home/ankurshaswat/MyFiles/Repos/Starlings/Code/external/glfw-3.1.2/tests /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests /home/ankurshaswat/MyFiles/Repos/Starlings/Code/bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ../bin/external/glfw-3.1.2/tests/CMakeFiles/cursor.dir/depend

