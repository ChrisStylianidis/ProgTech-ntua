# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas"

# Include any dependencies generated for this target.
include CMakeFiles/Gas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Gas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Gas.dir/flags.make

CMakeFiles/Gas.dir/main.cpp.obj: CMakeFiles/Gas.dir/flags.make
CMakeFiles/Gas.dir/main.cpp.obj: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Gas.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Gas.dir\main.cpp.obj -c "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\main.cpp"

CMakeFiles/Gas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Gas.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\main.cpp" > CMakeFiles\Gas.dir\main.cpp.i

CMakeFiles/Gas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Gas.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X86_64~2.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\main.cpp" -o CMakeFiles\Gas.dir\main.cpp.s

# Object files for target Gas
Gas_OBJECTS = \
"CMakeFiles/Gas.dir/main.cpp.obj"

# External object files for target Gas
Gas_EXTERNAL_OBJECTS =

Gas.exe: CMakeFiles/Gas.dir/main.cpp.obj
Gas.exe: CMakeFiles/Gas.dir/build.make
Gas.exe: CMakeFiles/Gas.dir/linklibs.rsp
Gas.exe: CMakeFiles/Gas.dir/objects1.rsp
Gas.exe: CMakeFiles/Gas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Gas.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Gas.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Gas.dir/build: Gas.exe

.PHONY : CMakeFiles/Gas.dir/build

CMakeFiles/Gas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Gas.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Gas.dir/clean

CMakeFiles/Gas.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas" "C:\Users\tooul\Desktop\Computer_Programming_NTUA\Second Semester\5i seira\Gas\CMakeFiles\Gas.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Gas.dir/depend
