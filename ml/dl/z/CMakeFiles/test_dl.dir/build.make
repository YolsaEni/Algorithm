# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = D:\Yolsa\Android\cmake-3.9.0-win32-x86\bin\cmake.exe

# The command to remove a file.
RM = D:\Yolsa\Android\cmake-3.9.0-win32-x86\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Yolsa\download\tmp\meter\src\ml\dl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Yolsa\download\tmp\meter\src\ml\dl\z

# Include any dependencies generated for this target.
include CMakeFiles/test_dl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_dl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_dl.dir/flags.make

CMakeFiles/test_dl.dir/test.cpp.obj: CMakeFiles/test_dl.dir/flags.make
CMakeFiles/test_dl.dir/test.cpp.obj: CMakeFiles/test_dl.dir/includes_CXX.rsp
CMakeFiles/test_dl.dir/test.cpp.obj: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Yolsa\download\tmp\meter\src\ml\dl\z\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_dl.dir/test.cpp.obj"
	D:\Yolsa\Android\TDM-GCC-32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test_dl.dir\test.cpp.obj -c D:\Yolsa\download\tmp\meter\src\ml\dl\test.cpp

CMakeFiles/test_dl.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_dl.dir/test.cpp.i"
	D:\Yolsa\Android\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Yolsa\download\tmp\meter\src\ml\dl\test.cpp > CMakeFiles\test_dl.dir\test.cpp.i

CMakeFiles/test_dl.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_dl.dir/test.cpp.s"
	D:\Yolsa\Android\TDM-GCC-32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Yolsa\download\tmp\meter\src\ml\dl\test.cpp -o CMakeFiles\test_dl.dir\test.cpp.s

CMakeFiles/test_dl.dir/test.cpp.obj.requires:

.PHONY : CMakeFiles/test_dl.dir/test.cpp.obj.requires

CMakeFiles/test_dl.dir/test.cpp.obj.provides: CMakeFiles/test_dl.dir/test.cpp.obj.requires
	$(MAKE) -f CMakeFiles\test_dl.dir\build.make CMakeFiles/test_dl.dir/test.cpp.obj.provides.build
.PHONY : CMakeFiles/test_dl.dir/test.cpp.obj.provides

CMakeFiles/test_dl.dir/test.cpp.obj.provides.build: CMakeFiles/test_dl.dir/test.cpp.obj


# Object files for target test_dl
test_dl_OBJECTS = \
"CMakeFiles/test_dl.dir/test.cpp.obj"

# External object files for target test_dl
test_dl_EXTERNAL_OBJECTS =

test_dl.exe: CMakeFiles/test_dl.dir/test.cpp.obj
test_dl.exe: CMakeFiles/test_dl.dir/build.make
test_dl.exe: D:/Yolsa/Android/opencv/x86/mingw/lib/libopencv_highgui2413.dll.a
test_dl.exe: D:/Yolsa/Android/opencv/x86/mingw/lib/libopencv_imgproc2413.dll.a
test_dl.exe: D:/Yolsa/Android/opencv/x86/mingw/lib/libopencv_core2413.dll.a
test_dl.exe: CMakeFiles/test_dl.dir/linklibs.rsp
test_dl.exe: CMakeFiles/test_dl.dir/objects1.rsp
test_dl.exe: CMakeFiles/test_dl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Yolsa\download\tmp\meter\src\ml\dl\z\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_dl.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_dl.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_dl.dir/build: test_dl.exe

.PHONY : CMakeFiles/test_dl.dir/build

CMakeFiles/test_dl.dir/requires: CMakeFiles/test_dl.dir/test.cpp.obj.requires

.PHONY : CMakeFiles/test_dl.dir/requires

CMakeFiles/test_dl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_dl.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_dl.dir/clean

CMakeFiles/test_dl.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Yolsa\download\tmp\meter\src\ml\dl D:\Yolsa\download\tmp\meter\src\ml\dl D:\Yolsa\download\tmp\meter\src\ml\dl\z D:\Yolsa\download\tmp\meter\src\ml\dl\z D:\Yolsa\download\tmp\meter\src\ml\dl\z\CMakeFiles\test_dl.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_dl.dir/depend

