# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\Program\msys64\mingw64\bin\cmake.exe

# The command to remove a file.
RM = F:\Program\msys64\mingw64\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\WORKSPACE\C++\CmakeEntry\library_build03

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\WORKSPACE\C++\CmakeEntry\library_build03\build

# Include any dependencies generated for this target.
include lib/math/CMakeFiles/math.dir/depend.make

# Include the progress variables for this target.
include lib/math/CMakeFiles/math.dir/progress.make

# Include the compile flags for this target's objects.
include lib/math/CMakeFiles/math.dir/flags.make

lib/math/CMakeFiles/math.dir/operations.cpp.obj: lib/math/CMakeFiles/math.dir/flags.make
lib/math/CMakeFiles/math.dir/operations.cpp.obj: ../lib/math/operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\WORKSPACE\C++\CmakeEntry\library_build03\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/math/CMakeFiles/math.dir/operations.cpp.obj"
	cd /d F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math && F:\Program\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\math.dir\operations.cpp.obj -c F:\WORKSPACE\C++\CmakeEntry\library_build03\lib\math\operations.cpp

lib/math/CMakeFiles/math.dir/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/math.dir/operations.cpp.i"
	cd /d F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math && F:\Program\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\WORKSPACE\C++\CmakeEntry\library_build03\lib\math\operations.cpp > CMakeFiles\math.dir\operations.cpp.i

lib/math/CMakeFiles/math.dir/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/math.dir/operations.cpp.s"
	cd /d F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math && F:\Program\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\WORKSPACE\C++\CmakeEntry\library_build03\lib\math\operations.cpp -o CMakeFiles\math.dir\operations.cpp.s

# Object files for target math
math_OBJECTS = \
"CMakeFiles/math.dir/operations.cpp.obj"

# External object files for target math
math_EXTERNAL_OBJECTS =

lib/libmath.dll: lib/math/CMakeFiles/math.dir/operations.cpp.obj
lib/libmath.dll: lib/math/CMakeFiles/math.dir/build.make
lib/libmath.dll: lib/math/CMakeFiles/math.dir/linklibs.rsp
lib/libmath.dll: lib/math/CMakeFiles/math.dir/objects1.rsp
lib/libmath.dll: lib/math/CMakeFiles/math.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\WORKSPACE\C++\CmakeEntry\library_build03\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ..\libmath.dll"
	cd /d F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\math.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/math/CMakeFiles/math.dir/build: lib/libmath.dll

.PHONY : lib/math/CMakeFiles/math.dir/build

lib/math/CMakeFiles/math.dir/clean:
	cd /d F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math && $(CMAKE_COMMAND) -P CMakeFiles\math.dir\cmake_clean.cmake
.PHONY : lib/math/CMakeFiles/math.dir/clean

lib/math/CMakeFiles/math.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\WORKSPACE\C++\CmakeEntry\library_build03 F:\WORKSPACE\C++\CmakeEntry\library_build03\lib\math F:\WORKSPACE\C++\CmakeEntry\library_build03\build F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math F:\WORKSPACE\C++\CmakeEntry\library_build03\build\lib\math\CMakeFiles\math.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/math/CMakeFiles/math.dir/depend

