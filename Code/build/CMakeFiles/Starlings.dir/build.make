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
include CMakeFiles/Starlings.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Starlings.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Starlings.dir/flags.make

CMakeFiles/Starlings.dir/src/main.cpp.o: CMakeFiles/Starlings.dir/flags.make
CMakeFiles/Starlings.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Starlings.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Starlings.dir/src/main.cpp.o -c /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/main.cpp

CMakeFiles/Starlings.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Starlings.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/main.cpp > CMakeFiles/Starlings.dir/src/main.cpp.i

CMakeFiles/Starlings.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Starlings.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/main.cpp -o CMakeFiles/Starlings.dir/src/main.cpp.s

CMakeFiles/Starlings.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Starlings.dir/src/main.cpp.o.requires

CMakeFiles/Starlings.dir/src/main.cpp.o.provides: CMakeFiles/Starlings.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Starlings.dir/build.make CMakeFiles/Starlings.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Starlings.dir/src/main.cpp.o.provides

CMakeFiles/Starlings.dir/src/main.cpp.o.provides.build: CMakeFiles/Starlings.dir/src/main.cpp.o


CMakeFiles/Starlings.dir/src/shader.cpp.o: CMakeFiles/Starlings.dir/flags.make
CMakeFiles/Starlings.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Starlings.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Starlings.dir/src/shader.cpp.o -c /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/shader.cpp

CMakeFiles/Starlings.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Starlings.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/shader.cpp > CMakeFiles/Starlings.dir/src/shader.cpp.i

CMakeFiles/Starlings.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Starlings.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/shader.cpp -o CMakeFiles/Starlings.dir/src/shader.cpp.s

CMakeFiles/Starlings.dir/src/shader.cpp.o.requires:

.PHONY : CMakeFiles/Starlings.dir/src/shader.cpp.o.requires

CMakeFiles/Starlings.dir/src/shader.cpp.o.provides: CMakeFiles/Starlings.dir/src/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/Starlings.dir/build.make CMakeFiles/Starlings.dir/src/shader.cpp.o.provides.build
.PHONY : CMakeFiles/Starlings.dir/src/shader.cpp.o.provides

CMakeFiles/Starlings.dir/src/shader.cpp.o.provides.build: CMakeFiles/Starlings.dir/src/shader.cpp.o


CMakeFiles/Starlings.dir/src/texture.cpp.o: CMakeFiles/Starlings.dir/flags.make
CMakeFiles/Starlings.dir/src/texture.cpp.o: ../src/texture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Starlings.dir/src/texture.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Starlings.dir/src/texture.cpp.o -c /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/texture.cpp

CMakeFiles/Starlings.dir/src/texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Starlings.dir/src/texture.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/texture.cpp > CMakeFiles/Starlings.dir/src/texture.cpp.i

CMakeFiles/Starlings.dir/src/texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Starlings.dir/src/texture.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ankurshaswat/MyFiles/Repos/Starlings/Code/src/texture.cpp -o CMakeFiles/Starlings.dir/src/texture.cpp.s

CMakeFiles/Starlings.dir/src/texture.cpp.o.requires:

.PHONY : CMakeFiles/Starlings.dir/src/texture.cpp.o.requires

CMakeFiles/Starlings.dir/src/texture.cpp.o.provides: CMakeFiles/Starlings.dir/src/texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/Starlings.dir/build.make CMakeFiles/Starlings.dir/src/texture.cpp.o.provides.build
.PHONY : CMakeFiles/Starlings.dir/src/texture.cpp.o.provides

CMakeFiles/Starlings.dir/src/texture.cpp.o.provides.build: CMakeFiles/Starlings.dir/src/texture.cpp.o


# Object files for target Starlings
Starlings_OBJECTS = \
"CMakeFiles/Starlings.dir/src/main.cpp.o" \
"CMakeFiles/Starlings.dir/src/shader.cpp.o" \
"CMakeFiles/Starlings.dir/src/texture.cpp.o"

# External object files for target Starlings
Starlings_EXTERNAL_OBJECTS =

../bin/Starlings: CMakeFiles/Starlings.dir/src/main.cpp.o
../bin/Starlings: CMakeFiles/Starlings.dir/src/shader.cpp.o
../bin/Starlings: CMakeFiles/Starlings.dir/src/texture.cpp.o
../bin/Starlings: CMakeFiles/Starlings.dir/build.make
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/Starlings: ../bin/external/glfw-3.1.2/src/libglfw3.a
../bin/Starlings: ../bin/external/libGLEW_1130.a
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libGLU.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/librt.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libm.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXrandr.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXinerama.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXi.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXcursor.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/librt.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libm.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libX11.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXrandr.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXinerama.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXi.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXxf86vm.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libXcursor.so
../bin/Starlings: /usr/lib/x86_64-linux-gnu/libGL.so
../bin/Starlings: CMakeFiles/Starlings.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../bin/Starlings"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Starlings.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Starlings.dir/build: ../bin/Starlings

.PHONY : CMakeFiles/Starlings.dir/build

CMakeFiles/Starlings.dir/requires: CMakeFiles/Starlings.dir/src/main.cpp.o.requires
CMakeFiles/Starlings.dir/requires: CMakeFiles/Starlings.dir/src/shader.cpp.o.requires
CMakeFiles/Starlings.dir/requires: CMakeFiles/Starlings.dir/src/texture.cpp.o.requires

.PHONY : CMakeFiles/Starlings.dir/requires

CMakeFiles/Starlings.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Starlings.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Starlings.dir/clean

CMakeFiles/Starlings.dir/depend:
	cd /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ankurshaswat/MyFiles/Repos/Starlings/Code /home/ankurshaswat/MyFiles/Repos/Starlings/Code /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build /home/ankurshaswat/MyFiles/Repos/Starlings/Code/build/CMakeFiles/Starlings.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Starlings.dir/depend

