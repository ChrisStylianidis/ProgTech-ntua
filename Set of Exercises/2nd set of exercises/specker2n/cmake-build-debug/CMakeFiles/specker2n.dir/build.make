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
CMAKE_SOURCE_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/specker2n.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/specker2n.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/specker2n.dir/flags.make

CMakeFiles/specker2n.dir/main.cpp.obj: CMakeFiles/specker2n.dir/flags.make
CMakeFiles/specker2n.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/specker2n.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\specker2n.dir\main.cpp.obj -c "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\main.cpp"

CMakeFiles/specker2n.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/specker2n.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\main.cpp" > CMakeFiles\specker2n.dir\main.cpp.i

CMakeFiles/specker2n.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/specker2n.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\main.cpp" -o CMakeFiles\specker2n.dir\main.cpp.s

# Object files for target specker2n
specker2n_OBJECTS = \
"CMakeFiles/specker2n.dir/main.cpp.obj"

# External object files for target specker2n
specker2n_EXTERNAL_OBJECTS =

specker2n.exe: CMakeFiles/specker2n.dir/main.cpp.obj
specker2n.exe: CMakeFiles/specker2n.dir/build.make
specker2n.exe: CMakeFiles/specker2n.dir/linklibs.rsp
specker2n.exe: CMakeFiles/specker2n.dir/objects1.rsp
specker2n.exe: CMakeFiles/specker2n.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable specker2n.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\specker2n.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/specker2n.dir/build: specker2n.exe

.PHONY : CMakeFiles/specker2n.dir/build

CMakeFiles/specker2n.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\specker2n.dir\cmake_clean.cmake
.PHONY : CMakeFiles/specker2n.dir/clean

CMakeFiles/specker2n.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\2i seira\specker2n\cmake-build-debug\CMakeFiles\specker2n.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/specker2n.dir/depend

