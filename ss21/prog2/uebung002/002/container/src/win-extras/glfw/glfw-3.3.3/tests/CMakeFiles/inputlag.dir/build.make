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
include tests/CMakeFiles/inputlag.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/inputlag.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/inputlag.dir/flags.make

tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/inputlag.c.obj: tests/inputlag.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/inputlag.dir/inputlag.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inputlag.dir/inputlag.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/inputlag.c"

tests/CMakeFiles/inputlag.dir/inputlag.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/inputlag.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/inputlag.c" > CMakeFiles/inputlag.dir/inputlag.c.i

tests/CMakeFiles/inputlag.dir/inputlag.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/inputlag.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/inputlag.c" -o CMakeFiles/inputlag.dir/inputlag.c.s

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inputlag.dir/__/deps/getopt.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c"

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/getopt.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c" > CMakeFiles/inputlag.dir/__/deps/getopt.c.i

tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/getopt.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c" -o CMakeFiles/inputlag.dir/__/deps/getopt.c.s

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/inputlag.dir/flags.make
tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/inputlag.dir/includes_C.rsp
tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c"

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" > CMakeFiles/inputlag.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" -o CMakeFiles/inputlag.dir/__/deps/glad_gl.c.s

# Object files for target inputlag
inputlag_OBJECTS = \
"CMakeFiles/inputlag.dir/inputlag.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/getopt.c.obj" \
"CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj"

# External object files for target inputlag
inputlag_EXTERNAL_OBJECTS =

tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/inputlag.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/__/deps/getopt.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/__/deps/glad_gl.c.obj
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/build.make
tests/inputlag.exe: src/libglfw3dll.a
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/linklibs.rsp
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/objects1.rsp
tests/inputlag.exe: tests/CMakeFiles/inputlag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable inputlag.exe"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inputlag.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/inputlag.dir/build: tests/inputlag.exe

.PHONY : tests/CMakeFiles/inputlag.dir/build

tests/CMakeFiles/inputlag.dir/clean:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -P CMakeFiles/inputlag.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/inputlag.dir/clean

tests/CMakeFiles/inputlag.dir/depend:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/CMakeFiles/inputlag.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/inputlag.dir/depend

