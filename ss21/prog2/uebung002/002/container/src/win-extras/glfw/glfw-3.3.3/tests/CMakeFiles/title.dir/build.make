# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_SOURCE_DIR = "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3"

# Include any dependencies generated for this target.
include tests/CMakeFiles/title.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/title.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/title.dir/flags.make

tests/CMakeFiles/title.dir/title.c.obj: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/title.c.obj: tests/CMakeFiles/title.dir/includes_C.rsp
tests/CMakeFiles/title.dir/title.c.obj: tests/title.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/title.dir/title.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/title.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/title.c"

tests/CMakeFiles/title.dir/title.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/title.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/title.c" > CMakeFiles/title.dir/title.c.i

tests/CMakeFiles/title.dir/title.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/title.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/title.c" -o CMakeFiles/title.dir/title.c.s

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/title.dir/flags.make
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/title.dir/includes_C.rsp
tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/title.dir/__/deps/glad_gl.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c"

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/title.dir/__/deps/glad_gl.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" > CMakeFiles/title.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/title.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/title.dir/__/deps/glad_gl.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" -o CMakeFiles/title.dir/__/deps/glad_gl.c.s

# Object files for target title
title_OBJECTS = \
"CMakeFiles/title.dir/title.c.obj" \
"CMakeFiles/title.dir/__/deps/glad_gl.c.obj"

# External object files for target title
title_EXTERNAL_OBJECTS =

tests/title.exe: tests/CMakeFiles/title.dir/title.c.obj
tests/title.exe: tests/CMakeFiles/title.dir/__/deps/glad_gl.c.obj
tests/title.exe: tests/CMakeFiles/title.dir/build.make
tests/title.exe: src/libglfw3dll.a
tests/title.exe: tests/CMakeFiles/title.dir/linklibs.rsp
tests/title.exe: tests/CMakeFiles/title.dir/objects1.rsp
tests/title.exe: tests/CMakeFiles/title.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable title.exe"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/title.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/title.dir/build: tests/title.exe

.PHONY : tests/CMakeFiles/title.dir/build

tests/CMakeFiles/title.dir/clean:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -P CMakeFiles/title.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/title.dir/clean

tests/CMakeFiles/title.dir/depend:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/CMakeFiles/title.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/title.dir/depend
