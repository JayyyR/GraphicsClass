# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/f85/jracosta/427/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/f85/jracosta/427/HW2

# Include any dependencies generated for this target.
include CMakeFiles/hw2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw2.dir/flags.make

CMakeFiles/hw2.dir/src/vec3d.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/vec3d.cpp.o: src/vec3d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/vec3d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/vec3d.cpp.o -c /home/f85/jracosta/427/HW2/src/vec3d.cpp

CMakeFiles/hw2.dir/src/vec3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/vec3d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/vec3d.cpp > CMakeFiles/hw2.dir/src/vec3d.cpp.i

CMakeFiles/hw2.dir/src/vec3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/vec3d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/vec3d.cpp -o CMakeFiles/hw2.dir/src/vec3d.cpp.s

CMakeFiles/hw2.dir/src/vec3d.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/vec3d.cpp.o.requires

CMakeFiles/hw2.dir/src/vec3d.cpp.o.provides: CMakeFiles/hw2.dir/src/vec3d.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/vec3d.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/vec3d.cpp.o.provides

CMakeFiles/hw2.dir/src/vec3d.cpp.o.provides.build: CMakeFiles/hw2.dir/src/vec3d.cpp.o

CMakeFiles/hw2.dir/src/color.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/color.cpp.o: src/color.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/color.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/color.cpp.o -c /home/f85/jracosta/427/HW2/src/color.cpp

CMakeFiles/hw2.dir/src/color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/color.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/color.cpp > CMakeFiles/hw2.dir/src/color.cpp.i

CMakeFiles/hw2.dir/src/color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/color.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/color.cpp -o CMakeFiles/hw2.dir/src/color.cpp.s

CMakeFiles/hw2.dir/src/color.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/color.cpp.o.requires

CMakeFiles/hw2.dir/src/color.cpp.o.provides: CMakeFiles/hw2.dir/src/color.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/color.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/color.cpp.o.provides

CMakeFiles/hw2.dir/src/color.cpp.o.provides.build: CMakeFiles/hw2.dir/src/color.cpp.o

CMakeFiles/hw2.dir/src/camera.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/camera.cpp.o: src/camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/camera.cpp.o -c /home/f85/jracosta/427/HW2/src/camera.cpp

CMakeFiles/hw2.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/camera.cpp > CMakeFiles/hw2.dir/src/camera.cpp.i

CMakeFiles/hw2.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/camera.cpp -o CMakeFiles/hw2.dir/src/camera.cpp.s

CMakeFiles/hw2.dir/src/camera.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/camera.cpp.o.requires

CMakeFiles/hw2.dir/src/camera.cpp.o.provides: CMakeFiles/hw2.dir/src/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/camera.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/camera.cpp.o.provides

CMakeFiles/hw2.dir/src/camera.cpp.o.provides.build: CMakeFiles/hw2.dir/src/camera.cpp.o

CMakeFiles/hw2.dir/src/image.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/image.cpp.o: src/image.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/image.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/image.cpp.o -c /home/f85/jracosta/427/HW2/src/image.cpp

CMakeFiles/hw2.dir/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/image.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/image.cpp > CMakeFiles/hw2.dir/src/image.cpp.i

CMakeFiles/hw2.dir/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/image.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/image.cpp -o CMakeFiles/hw2.dir/src/image.cpp.s

CMakeFiles/hw2.dir/src/image.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/image.cpp.o.requires

CMakeFiles/hw2.dir/src/image.cpp.o.provides: CMakeFiles/hw2.dir/src/image.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/image.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/image.cpp.o.provides

CMakeFiles/hw2.dir/src/image.cpp.o.provides.build: CMakeFiles/hw2.dir/src/image.cpp.o

CMakeFiles/hw2.dir/src/transformation3d.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/transformation3d.cpp.o: src/transformation3d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/transformation3d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/transformation3d.cpp.o -c /home/f85/jracosta/427/HW2/src/transformation3d.cpp

CMakeFiles/hw2.dir/src/transformation3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/transformation3d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/transformation3d.cpp > CMakeFiles/hw2.dir/src/transformation3d.cpp.i

CMakeFiles/hw2.dir/src/transformation3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/transformation3d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/transformation3d.cpp -o CMakeFiles/hw2.dir/src/transformation3d.cpp.s

CMakeFiles/hw2.dir/src/transformation3d.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/transformation3d.cpp.o.requires

CMakeFiles/hw2.dir/src/transformation3d.cpp.o.provides: CMakeFiles/hw2.dir/src/transformation3d.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/transformation3d.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/transformation3d.cpp.o.provides

CMakeFiles/hw2.dir/src/transformation3d.cpp.o.provides.build: CMakeFiles/hw2.dir/src/transformation3d.cpp.o

CMakeFiles/hw2.dir/src/mat3d.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/mat3d.cpp.o: src/mat3d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/mat3d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/mat3d.cpp.o -c /home/f85/jracosta/427/HW2/src/mat3d.cpp

CMakeFiles/hw2.dir/src/mat3d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/mat3d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/mat3d.cpp > CMakeFiles/hw2.dir/src/mat3d.cpp.i

CMakeFiles/hw2.dir/src/mat3d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/mat3d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/mat3d.cpp -o CMakeFiles/hw2.dir/src/mat3d.cpp.s

CMakeFiles/hw2.dir/src/mat3d.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/mat3d.cpp.o.requires

CMakeFiles/hw2.dir/src/mat3d.cpp.o.provides: CMakeFiles/hw2.dir/src/mat3d.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/mat3d.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/mat3d.cpp.o.provides

CMakeFiles/hw2.dir/src/mat3d.cpp.o.provides.build: CMakeFiles/hw2.dir/src/mat3d.cpp.o

CMakeFiles/hw2.dir/src/triangle.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/triangle.cpp.o: src/triangle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/triangle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/triangle.cpp.o -c /home/f85/jracosta/427/HW2/src/triangle.cpp

CMakeFiles/hw2.dir/src/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/triangle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/triangle.cpp > CMakeFiles/hw2.dir/src/triangle.cpp.i

CMakeFiles/hw2.dir/src/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/triangle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/triangle.cpp -o CMakeFiles/hw2.dir/src/triangle.cpp.s

CMakeFiles/hw2.dir/src/triangle.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/triangle.cpp.o.requires

CMakeFiles/hw2.dir/src/triangle.cpp.o.provides: CMakeFiles/hw2.dir/src/triangle.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/triangle.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/triangle.cpp.o.provides

CMakeFiles/hw2.dir/src/triangle.cpp.o.provides.build: CMakeFiles/hw2.dir/src/triangle.cpp.o

CMakeFiles/hw2.dir/src/vec2d.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/vec2d.cpp.o: src/vec2d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/vec2d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/vec2d.cpp.o -c /home/f85/jracosta/427/HW2/src/vec2d.cpp

CMakeFiles/hw2.dir/src/vec2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/vec2d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/vec2d.cpp > CMakeFiles/hw2.dir/src/vec2d.cpp.i

CMakeFiles/hw2.dir/src/vec2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/vec2d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/vec2d.cpp -o CMakeFiles/hw2.dir/src/vec2d.cpp.s

CMakeFiles/hw2.dir/src/vec2d.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/vec2d.cpp.o.requires

CMakeFiles/hw2.dir/src/vec2d.cpp.o.provides: CMakeFiles/hw2.dir/src/vec2d.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/vec2d.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/vec2d.cpp.o.provides

CMakeFiles/hw2.dir/src/vec2d.cpp.o.provides.build: CMakeFiles/hw2.dir/src/vec2d.cpp.o

CMakeFiles/hw2.dir/src/mat2d.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/mat2d.cpp.o: src/mat2d.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/mat2d.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/mat2d.cpp.o -c /home/f85/jracosta/427/HW2/src/mat2d.cpp

CMakeFiles/hw2.dir/src/mat2d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/mat2d.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/mat2d.cpp > CMakeFiles/hw2.dir/src/mat2d.cpp.i

CMakeFiles/hw2.dir/src/mat2d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/mat2d.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/mat2d.cpp -o CMakeFiles/hw2.dir/src/mat2d.cpp.s

CMakeFiles/hw2.dir/src/mat2d.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/mat2d.cpp.o.requires

CMakeFiles/hw2.dir/src/mat2d.cpp.o.provides: CMakeFiles/hw2.dir/src/mat2d.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/mat2d.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/mat2d.cpp.o.provides

CMakeFiles/hw2.dir/src/mat2d.cpp.o.provides.build: CMakeFiles/hw2.dir/src/mat2d.cpp.o

CMakeFiles/hw2.dir/src/ray.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/src/ray.cpp.o: src/ray.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/src/ray.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/src/ray.cpp.o -c /home/f85/jracosta/427/HW2/src/ray.cpp

CMakeFiles/hw2.dir/src/ray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/src/ray.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/src/ray.cpp > CMakeFiles/hw2.dir/src/ray.cpp.i

CMakeFiles/hw2.dir/src/ray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/src/ray.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/src/ray.cpp -o CMakeFiles/hw2.dir/src/ray.cpp.s

CMakeFiles/hw2.dir/src/ray.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/src/ray.cpp.o.requires

CMakeFiles/hw2.dir/src/ray.cpp.o.provides: CMakeFiles/hw2.dir/src/ray.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/src/ray.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/src/ray.cpp.o.provides

CMakeFiles/hw2.dir/src/ray.cpp.o.provides.build: CMakeFiles/hw2.dir/src/ray.cpp.o

CMakeFiles/hw2.dir/bin/hw2.cpp.o: CMakeFiles/hw2.dir/flags.make
CMakeFiles/hw2.dir/bin/hw2.cpp.o: bin/hw2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/f85/jracosta/427/HW2/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/hw2.dir/bin/hw2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/hw2.dir/bin/hw2.cpp.o -c /home/f85/jracosta/427/HW2/bin/hw2.cpp

CMakeFiles/hw2.dir/bin/hw2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hw2.dir/bin/hw2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/f85/jracosta/427/HW2/bin/hw2.cpp > CMakeFiles/hw2.dir/bin/hw2.cpp.i

CMakeFiles/hw2.dir/bin/hw2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hw2.dir/bin/hw2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/f85/jracosta/427/HW2/bin/hw2.cpp -o CMakeFiles/hw2.dir/bin/hw2.cpp.s

CMakeFiles/hw2.dir/bin/hw2.cpp.o.requires:
.PHONY : CMakeFiles/hw2.dir/bin/hw2.cpp.o.requires

CMakeFiles/hw2.dir/bin/hw2.cpp.o.provides: CMakeFiles/hw2.dir/bin/hw2.cpp.o.requires
	$(MAKE) -f CMakeFiles/hw2.dir/build.make CMakeFiles/hw2.dir/bin/hw2.cpp.o.provides.build
.PHONY : CMakeFiles/hw2.dir/bin/hw2.cpp.o.provides

CMakeFiles/hw2.dir/bin/hw2.cpp.o.provides.build: CMakeFiles/hw2.dir/bin/hw2.cpp.o

# Object files for target hw2
hw2_OBJECTS = \
"CMakeFiles/hw2.dir/src/vec3d.cpp.o" \
"CMakeFiles/hw2.dir/src/color.cpp.o" \
"CMakeFiles/hw2.dir/src/camera.cpp.o" \
"CMakeFiles/hw2.dir/src/image.cpp.o" \
"CMakeFiles/hw2.dir/src/transformation3d.cpp.o" \
"CMakeFiles/hw2.dir/src/mat3d.cpp.o" \
"CMakeFiles/hw2.dir/src/triangle.cpp.o" \
"CMakeFiles/hw2.dir/src/vec2d.cpp.o" \
"CMakeFiles/hw2.dir/src/mat2d.cpp.o" \
"CMakeFiles/hw2.dir/src/ray.cpp.o" \
"CMakeFiles/hw2.dir/bin/hw2.cpp.o"

# External object files for target hw2
hw2_EXTERNAL_OBJECTS =

hw2: CMakeFiles/hw2.dir/src/vec3d.cpp.o
hw2: CMakeFiles/hw2.dir/src/color.cpp.o
hw2: CMakeFiles/hw2.dir/src/camera.cpp.o
hw2: CMakeFiles/hw2.dir/src/image.cpp.o
hw2: CMakeFiles/hw2.dir/src/transformation3d.cpp.o
hw2: CMakeFiles/hw2.dir/src/mat3d.cpp.o
hw2: CMakeFiles/hw2.dir/src/triangle.cpp.o
hw2: CMakeFiles/hw2.dir/src/vec2d.cpp.o
hw2: CMakeFiles/hw2.dir/src/mat2d.cpp.o
hw2: CMakeFiles/hw2.dir/src/ray.cpp.o
hw2: CMakeFiles/hw2.dir/bin/hw2.cpp.o
hw2: CMakeFiles/hw2.dir/build.make
hw2: CMakeFiles/hw2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable hw2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw2.dir/build: hw2
.PHONY : CMakeFiles/hw2.dir/build

CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/vec3d.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/color.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/camera.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/image.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/transformation3d.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/mat3d.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/triangle.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/vec2d.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/mat2d.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/src/ray.cpp.o.requires
CMakeFiles/hw2.dir/requires: CMakeFiles/hw2.dir/bin/hw2.cpp.o.requires
.PHONY : CMakeFiles/hw2.dir/requires

CMakeFiles/hw2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw2.dir/clean

CMakeFiles/hw2.dir/depend:
	cd /home/f85/jracosta/427/HW2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/f85/jracosta/427/HW2 /home/f85/jracosta/427/HW2 /home/f85/jracosta/427/HW2 /home/f85/jracosta/427/HW2 /home/f85/jracosta/427/HW2/CMakeFiles/hw2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw2.dir/depend

