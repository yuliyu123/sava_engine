# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/dev/sava_detecator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/dev/sava_detecator/build

# Include any dependencies generated for this target.
include CMakeFiles/sava_scan.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sava_scan.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sava_scan.dir/flags.make

CMakeFiles/sava_scan.dir/main.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sava_scan.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/main.cpp.o -c /root/dev/sava_detecator/main.cpp

CMakeFiles/sava_scan.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/main.cpp > CMakeFiles/sava_scan.dir/main.cpp.i

CMakeFiles/sava_scan.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/main.cpp -o CMakeFiles/sava_scan.dir/main.cpp.s

CMakeFiles/sava_scan.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/main.cpp.o.requires

CMakeFiles/sava_scan.dir/main.cpp.o.provides: CMakeFiles/sava_scan.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/main.cpp.o.provides

CMakeFiles/sava_scan.dir/main.cpp.o.provides.build: CMakeFiles/sava_scan.dir/main.cpp.o


CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o: ../src/AesUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o -c /root/dev/sava_detecator/src/AesUtil.cpp

CMakeFiles/sava_scan.dir/src/AesUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/AesUtil.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/AesUtil.cpp > CMakeFiles/sava_scan.dir/src/AesUtil.cpp.i

CMakeFiles/sava_scan.dir/src/AesUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/AesUtil.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/AesUtil.cpp -o CMakeFiles/sava_scan.dir/src/AesUtil.cpp.s

CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.requires

CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.provides: CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.provides

CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o


CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o: ../src/DbConnector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o -c /root/dev/sava_detecator/src/DbConnector.cpp

CMakeFiles/sava_scan.dir/src/DbConnector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/DbConnector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/DbConnector.cpp > CMakeFiles/sava_scan.dir/src/DbConnector.cpp.i

CMakeFiles/sava_scan.dir/src/DbConnector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/DbConnector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/DbConnector.cpp -o CMakeFiles/sava_scan.dir/src/DbConnector.cpp.s

CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.requires

CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.provides: CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.provides

CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o


CMakeFiles/sava_scan.dir/src/DbService.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/DbService.cpp.o: ../src/DbService.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/sava_scan.dir/src/DbService.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/DbService.cpp.o -c /root/dev/sava_detecator/src/DbService.cpp

CMakeFiles/sava_scan.dir/src/DbService.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/DbService.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/DbService.cpp > CMakeFiles/sava_scan.dir/src/DbService.cpp.i

CMakeFiles/sava_scan.dir/src/DbService.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/DbService.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/DbService.cpp -o CMakeFiles/sava_scan.dir/src/DbService.cpp.s

CMakeFiles/sava_scan.dir/src/DbService.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/DbService.cpp.o.requires

CMakeFiles/sava_scan.dir/src/DbService.cpp.o.provides: CMakeFiles/sava_scan.dir/src/DbService.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/DbService.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/DbService.cpp.o.provides

CMakeFiles/sava_scan.dir/src/DbService.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/DbService.cpp.o


CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o: ../src/SavaDetecator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o -c /root/dev/sava_detecator/src/SavaDetecator.cpp

CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/SavaDetecator.cpp > CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.i

CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/SavaDetecator.cpp -o CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.s

CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.requires

CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.provides: CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.provides

CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o


CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o: ../src/TaskRunner.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o -c /root/dev/sava_detecator/src/TaskRunner.cpp

CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/TaskRunner.cpp > CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.i

CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/TaskRunner.cpp -o CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.s

CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.requires

CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.provides: CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.provides

CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o


CMakeFiles/sava_scan.dir/src/common.cpp.o: CMakeFiles/sava_scan.dir/flags.make
CMakeFiles/sava_scan.dir/src/common.cpp.o: ../src/common.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/sava_scan.dir/src/common.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sava_scan.dir/src/common.cpp.o -c /root/dev/sava_detecator/src/common.cpp

CMakeFiles/sava_scan.dir/src/common.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sava_scan.dir/src/common.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/dev/sava_detecator/src/common.cpp > CMakeFiles/sava_scan.dir/src/common.cpp.i

CMakeFiles/sava_scan.dir/src/common.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sava_scan.dir/src/common.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/dev/sava_detecator/src/common.cpp -o CMakeFiles/sava_scan.dir/src/common.cpp.s

CMakeFiles/sava_scan.dir/src/common.cpp.o.requires:

.PHONY : CMakeFiles/sava_scan.dir/src/common.cpp.o.requires

CMakeFiles/sava_scan.dir/src/common.cpp.o.provides: CMakeFiles/sava_scan.dir/src/common.cpp.o.requires
	$(MAKE) -f CMakeFiles/sava_scan.dir/build.make CMakeFiles/sava_scan.dir/src/common.cpp.o.provides.build
.PHONY : CMakeFiles/sava_scan.dir/src/common.cpp.o.provides

CMakeFiles/sava_scan.dir/src/common.cpp.o.provides.build: CMakeFiles/sava_scan.dir/src/common.cpp.o


# Object files for target sava_scan
sava_scan_OBJECTS = \
"CMakeFiles/sava_scan.dir/main.cpp.o" \
"CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o" \
"CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o" \
"CMakeFiles/sava_scan.dir/src/DbService.cpp.o" \
"CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o" \
"CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o" \
"CMakeFiles/sava_scan.dir/src/common.cpp.o"

# External object files for target sava_scan
sava_scan_EXTERNAL_OBJECTS =

../bin/sava_scan: CMakeFiles/sava_scan.dir/main.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/DbService.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/src/common.cpp.o
../bin/sava_scan: CMakeFiles/sava_scan.dir/build.make
../bin/sava_scan: CMakeFiles/sava_scan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/dev/sava_detecator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/sava_scan"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sava_scan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sava_scan.dir/build: ../bin/sava_scan

.PHONY : CMakeFiles/sava_scan.dir/build

CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/main.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/AesUtil.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/DbConnector.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/DbService.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/SavaDetecator.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/TaskRunner.cpp.o.requires
CMakeFiles/sava_scan.dir/requires: CMakeFiles/sava_scan.dir/src/common.cpp.o.requires

.PHONY : CMakeFiles/sava_scan.dir/requires

CMakeFiles/sava_scan.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sava_scan.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sava_scan.dir/clean

CMakeFiles/sava_scan.dir/depend:
	cd /root/dev/sava_detecator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/dev/sava_detecator /root/dev/sava_detecator /root/dev/sava_detecator/build /root/dev/sava_detecator/build /root/dev/sava_detecator/build/CMakeFiles/sava_scan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sava_scan.dir/depend

