# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/stackdemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stackdemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stackdemo.dir/flags.make

CMakeFiles/stackdemo.dir/main.cpp.obj: CMakeFiles/stackdemo.dir/flags.make
CMakeFiles/stackdemo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stackdemo.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\stackdemo.dir\main.cpp.obj -c "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\main.cpp"

CMakeFiles/stackdemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stackdemo.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\main.cpp" > CMakeFiles\stackdemo.dir\main.cpp.i

CMakeFiles/stackdemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stackdemo.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\main.cpp" -o CMakeFiles\stackdemo.dir\main.cpp.s

# Object files for target stackdemo
stackdemo_OBJECTS = \
"CMakeFiles/stackdemo.dir/main.cpp.obj"

# External object files for target stackdemo
stackdemo_EXTERNAL_OBJECTS =

stackdemo.exe: CMakeFiles/stackdemo.dir/main.cpp.obj
stackdemo.exe: CMakeFiles/stackdemo.dir/build.make
stackdemo.exe: CMakeFiles/stackdemo.dir/linklibs.rsp
stackdemo.exe: CMakeFiles/stackdemo.dir/objects1.rsp
stackdemo.exe: CMakeFiles/stackdemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stackdemo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\stackdemo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stackdemo.dir/build: stackdemo.exe

.PHONY : CMakeFiles/stackdemo.dir/build

CMakeFiles/stackdemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\stackdemo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/stackdemo.dir/clean

CMakeFiles/stackdemo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\1i seira\stackdemo\cmake-build-debug\CMakeFiles\stackdemo.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stackdemo.dir/depend
