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
include tests/CMakeFiles/iconify.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/iconify.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/iconify.dir/flags.make

tests/CMakeFiles/iconify.dir/iconify.c.obj: tests/CMakeFiles/iconify.dir/flags.make
tests/CMakeFiles/iconify.dir/iconify.c.obj: tests/CMakeFiles/iconify.dir/includes_C.rsp
tests/CMakeFiles/iconify.dir/iconify.c.obj: tests/iconify.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/iconify.dir/iconify.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/iconify.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/iconify.c"

tests/CMakeFiles/iconify.dir/iconify.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/iconify.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/iconify.c" > CMakeFiles/iconify.dir/iconify.c.i

tests/CMakeFiles/iconify.dir/iconify.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/iconify.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/iconify.c" -o CMakeFiles/iconify.dir/iconify.c.s

tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: tests/CMakeFiles/iconify.dir/flags.make
tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: tests/CMakeFiles/iconify.dir/includes_C.rsp
tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/__/deps/getopt.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c"

tests/CMakeFiles/iconify.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/getopt.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c" > CMakeFiles/iconify.dir/__/deps/getopt.c.i

tests/CMakeFiles/iconify.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/getopt.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/getopt.c" -o CMakeFiles/iconify.dir/__/deps/getopt.c.s

tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/iconify.dir/flags.make
tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: tests/CMakeFiles/iconify.dir/includes_C.rsp
tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj -c "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c"

tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/iconify.dir/__/deps/glad_gl.c.i"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" > CMakeFiles/iconify.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/iconify.dir/__/deps/glad_gl.c.s"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && /usr/bin/i686-w64-mingw32-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/deps/glad_gl.c" -o CMakeFiles/iconify.dir/__/deps/glad_gl.c.s

# Object files for target iconify
iconify_OBJECTS = \
"CMakeFiles/iconify.dir/iconify.c.obj" \
"CMakeFiles/iconify.dir/__/deps/getopt.c.obj" \
"CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj"

# External object files for target iconify
iconify_EXTERNAL_OBJECTS =

tests/iconify.exe: tests/CMakeFiles/iconify.dir/iconify.c.obj
tests/iconify.exe: tests/CMakeFiles/iconify.dir/__/deps/getopt.c.obj
tests/iconify.exe: tests/CMakeFiles/iconify.dir/__/deps/glad_gl.c.obj
tests/iconify.exe: tests/CMakeFiles/iconify.dir/build.make
tests/iconify.exe: src/libglfw3dll.a
tests/iconify.exe: tests/CMakeFiles/iconify.dir/linklibs.rsp
tests/iconify.exe: tests/CMakeFiles/iconify.dir/objects1.rsp
tests/iconify.exe: tests/CMakeFiles/iconify.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable iconify.exe"
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/iconify.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/iconify.dir/build: tests/iconify.exe

.PHONY : tests/CMakeFiles/iconify.dir/build

tests/CMakeFiles/iconify.dir/clean:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" && $(CMAKE_COMMAND) -P CMakeFiles/iconify.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/iconify.dir/clean

tests/CMakeFiles/iconify.dir/depend:
	cd "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests" "/home/louis/wichtiges/kempten/ss21/programmieren 2/uebungen/001/container/src/win-extras/glfw/glfw-3.3.3/tests/CMakeFiles/iconify.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : tests/CMakeFiles/iconify.dir/depend
