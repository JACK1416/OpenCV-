# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.12.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.12.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/apple/Documents/projects/opencv/1-7

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/apple/Documents/projects/opencv/1-7

# Include any dependencies generated for this target.
include CMakeFiles/chapter5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chapter5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chapter5.dir/flags.make

CMakeFiles/chapter5.dir/src/chapter5.cc.o: CMakeFiles/chapter5.dir/flags.make
CMakeFiles/chapter5.dir/src/chapter5.cc.o: src/chapter5.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/apple/Documents/projects/opencv/1-7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chapter5.dir/src/chapter5.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chapter5.dir/src/chapter5.cc.o -c /Users/apple/Documents/projects/opencv/1-7/src/chapter5.cc

CMakeFiles/chapter5.dir/src/chapter5.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chapter5.dir/src/chapter5.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/apple/Documents/projects/opencv/1-7/src/chapter5.cc > CMakeFiles/chapter5.dir/src/chapter5.cc.i

CMakeFiles/chapter5.dir/src/chapter5.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chapter5.dir/src/chapter5.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/apple/Documents/projects/opencv/1-7/src/chapter5.cc -o CMakeFiles/chapter5.dir/src/chapter5.cc.s

# Object files for target chapter5
chapter5_OBJECTS = \
"CMakeFiles/chapter5.dir/src/chapter5.cc.o"

# External object files for target chapter5
chapter5_EXTERNAL_OBJECTS =

bin/chapter5: CMakeFiles/chapter5.dir/src/chapter5.cc.o
bin/chapter5: CMakeFiles/chapter5.dir/build.make
bin/chapter5: /usr/local/lib/libopencv_dnn.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_ml.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_objdetect.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_shape.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_stitching.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_superres.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_videostab.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_calib3d.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_features2d.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_flann.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_highgui.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_photo.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_video.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_videoio.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_imgcodecs.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_imgproc.3.4.2.dylib
bin/chapter5: /usr/local/lib/libopencv_core.3.4.2.dylib
bin/chapter5: CMakeFiles/chapter5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/apple/Documents/projects/opencv/1-7/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/chapter5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chapter5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chapter5.dir/build: bin/chapter5

.PHONY : CMakeFiles/chapter5.dir/build

CMakeFiles/chapter5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chapter5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chapter5.dir/clean

CMakeFiles/chapter5.dir/depend:
	cd /Users/apple/Documents/projects/opencv/1-7 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/apple/Documents/projects/opencv/1-7 /Users/apple/Documents/projects/opencv/1-7 /Users/apple/Documents/projects/opencv/1-7 /Users/apple/Documents/projects/opencv/1-7 /Users/apple/Documents/projects/opencv/1-7/CMakeFiles/chapter5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chapter5.dir/depend

