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
CMAKE_SOURCE_DIR = F:\WORKSPACE\C++\CmakeEntry\library_fmt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\WORKSPACE\C++\CmakeEntry\library_fmt\build

# Include any dependencies generated for this target.
include CMakeFiles/fmt_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fmt_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fmt_demo.dir/flags.make

CMakeFiles/fmt_demo.dir/main.cpp.obj: CMakeFiles/fmt_demo.dir/flags.make
CMakeFiles/fmt_demo.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\WORKSPACE\C++\CmakeEntry\library_fmt\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fmt_demo.dir/main.cpp.obj"
	F:\Program\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\fmt_demo.dir\main.cpp.obj -c F:\WORKSPACE\C++\CmakeEntry\library_fmt\main.cpp

CMakeFiles/fmt_demo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fmt_demo.dir/main.cpp.i"
	F:\Program\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\WORKSPACE\C++\CmakeEntry\library_fmt\main.cpp > CMakeFiles\fmt_demo.dir\main.cpp.i

CMakeFiles/fmt_demo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fmt_demo.dir/main.cpp.s"
	F:\Program\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\WORKSPACE\C++\CmakeEntry\library_fmt\main.cpp -o CMakeFiles\fmt_demo.dir\main.cpp.s

# Object files for target fmt_demo
fmt_demo_OBJECTS = \
"CMakeFiles/fmt_demo.dir/main.cpp.obj"

# External object files for target fmt_demo
fmt_demo_EXTERNAL_OBJECTS =

bin/fmt_demo.exe: CMakeFiles/fmt_demo.dir/main.cpp.obj
bin/fmt_demo.exe: CMakeFiles/fmt_demo.dir/build.make
bin/fmt_demo.exe: F:/Program/msys64/mingw64/lib/libfmt.a
bin/fmt_demo.exe: CMakeFiles/fmt_demo.dir/linklibs.rsp
bin/fmt_demo.exe: CMakeFiles/fmt_demo.dir/objects1.rsp
bin/fmt_demo.exe: CMakeFiles/fmt_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\WORKSPACE\C++\CmakeEntry\library_fmt\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin\fmt_demo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fmt_demo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fmt_demo.dir/build: bin/fmt_demo.exe

.PHONY : CMakeFiles/fmt_demo.dir/build

CMakeFiles/fmt_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fmt_demo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fmt_demo.dir/clean

CMakeFiles/fmt_demo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\WORKSPACE\C++\CmakeEntry\library_fmt F:\WORKSPACE\C++\CmakeEntry\library_fmt F:\WORKSPACE\C++\CmakeEntry\library_fmt\build F:\WORKSPACE\C++\CmakeEntry\library_fmt\build F:\WORKSPACE\C++\CmakeEntry\library_fmt\build\CMakeFiles\fmt_demo.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fmt_demo.dir/depend

