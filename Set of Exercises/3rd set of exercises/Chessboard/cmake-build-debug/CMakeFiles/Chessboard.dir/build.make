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
CMAKE_SOURCE_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Chessboard.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Chessboard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Chessboard.dir/flags.make

CMakeFiles/Chessboard.dir/main.cpp.obj: CMakeFiles/Chessboard.dir/flags.make
CMakeFiles/Chessboard.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Chessboard.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Chessboard.dir\main.cpp.obj -c "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\main.cpp"

CMakeFiles/Chessboard.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Chessboard.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\main.cpp" > CMakeFiles\Chessboard.dir\main.cpp.i

CMakeFiles/Chessboard.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Chessboard.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\main.cpp" -o CMakeFiles\Chessboard.dir\main.cpp.s

# Object files for target Chessboard
Chessboard_OBJECTS = \
"CMakeFiles/Chessboard.dir/main.cpp.obj"

# External object files for target Chessboard
Chessboard_EXTERNAL_OBJECTS =

Chessboard.exe: CMakeFiles/Chessboard.dir/main.cpp.obj
Chessboard.exe: CMakeFiles/Chessboard.dir/build.make
Chessboard.exe: CMakeFiles/Chessboard.dir/linklibs.rsp
Chessboard.exe: CMakeFiles/Chessboard.dir/objects1.rsp
Chessboard.exe: CMakeFiles/Chessboard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Chessboard.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Chessboard.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Chessboard.dir/build: Chessboard.exe

.PHONY : CMakeFiles/Chessboard.dir/build

CMakeFiles/Chessboard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Chessboard.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Chessboard.dir/clean

CMakeFiles/Chessboard.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\3i seira\Chessboard\cmake-build-debug\CMakeFiles\Chessboard.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Chessboard.dir/depend

