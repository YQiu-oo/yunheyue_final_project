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
CMAKE_SOURCE_DIR = /workspaces/yunheyue/yunheyue_final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/yunheyue/yunheyue_final_project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/draw.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/draw.cpp.o: ../src/draw.cpp
src/CMakeFiles/src.dir/draw.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/yunheyue/yunheyue_final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/draw.cpp.o"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/draw.cpp.o -MF CMakeFiles/src.dir/draw.cpp.o.d -o CMakeFiles/src.dir/draw.cpp.o -c /workspaces/yunheyue/yunheyue_final_project/src/draw.cpp

src/CMakeFiles/src.dir/draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/draw.cpp.i"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/yunheyue/yunheyue_final_project/src/draw.cpp > CMakeFiles/src.dir/draw.cpp.i

src/CMakeFiles/src.dir/draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/draw.cpp.s"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/yunheyue/yunheyue_final_project/src/draw.cpp -o CMakeFiles/src.dir/draw.cpp.s

src/CMakeFiles/src.dir/graph.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/graph.cpp.o: ../src/graph.cpp
src/CMakeFiles/src.dir/graph.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/yunheyue/yunheyue_final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/graph.cpp.o"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/graph.cpp.o -MF CMakeFiles/src.dir/graph.cpp.o.d -o CMakeFiles/src.dir/graph.cpp.o -c /workspaces/yunheyue/yunheyue_final_project/src/graph.cpp

src/CMakeFiles/src.dir/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/graph.cpp.i"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/yunheyue/yunheyue_final_project/src/graph.cpp > CMakeFiles/src.dir/graph.cpp.i

src/CMakeFiles/src.dir/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/graph.cpp.s"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/yunheyue/yunheyue_final_project/src/graph.cpp -o CMakeFiles/src.dir/graph.cpp.s

src/CMakeFiles/src.dir/read_file.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/read_file.cpp.o: ../src/read_file.cpp
src/CMakeFiles/src.dir/read_file.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/yunheyue/yunheyue_final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/read_file.cpp.o"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/read_file.cpp.o -MF CMakeFiles/src.dir/read_file.cpp.o.d -o CMakeFiles/src.dir/read_file.cpp.o -c /workspaces/yunheyue/yunheyue_final_project/src/read_file.cpp

src/CMakeFiles/src.dir/read_file.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/read_file.cpp.i"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/yunheyue/yunheyue_final_project/src/read_file.cpp > CMakeFiles/src.dir/read_file.cpp.i

src/CMakeFiles/src.dir/read_file.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/read_file.cpp.s"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/yunheyue/yunheyue_final_project/src/read_file.cpp -o CMakeFiles/src.dir/read_file.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/draw.cpp.o" \
"CMakeFiles/src.dir/graph.cpp.o" \
"CMakeFiles/src.dir/read_file.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/draw.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/graph.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/read_file.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/yunheyue/yunheyue_final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libsrc.a"
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /workspaces/yunheyue/yunheyue_final_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /workspaces/yunheyue/yunheyue_final_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/yunheyue/yunheyue_final_project /workspaces/yunheyue/yunheyue_final_project/src /workspaces/yunheyue/yunheyue_final_project/build /workspaces/yunheyue/yunheyue_final_project/build/src /workspaces/yunheyue/yunheyue_final_project/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

