# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab.dir/flags.make

CMakeFiles/lab.dir/main.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab.dir/main.cpp.o -c /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/main.cpp

CMakeFiles/lab.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/main.cpp > CMakeFiles/lab.dir/main.cpp.i

CMakeFiles/lab.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/main.cpp -o CMakeFiles/lab.dir/main.cpp.s

CMakeFiles/lab.dir/Pipe.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/Pipe.cpp.o: ../Pipe.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/lab.dir/Pipe.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab.dir/Pipe.cpp.o -c /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/Pipe.cpp

CMakeFiles/lab.dir/Pipe.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/Pipe.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/Pipe.cpp > CMakeFiles/lab.dir/Pipe.cpp.i

CMakeFiles/lab.dir/Pipe.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/Pipe.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/Pipe.cpp -o CMakeFiles/lab.dir/Pipe.cpp.s

CMakeFiles/lab.dir/verification.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/verification.cpp.o: ../verification.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/lab.dir/verification.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab.dir/verification.cpp.o -c /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/verification.cpp

CMakeFiles/lab.dir/verification.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/verification.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/verification.cpp > CMakeFiles/lab.dir/verification.cpp.i

CMakeFiles/lab.dir/verification.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/verification.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/verification.cpp -o CMakeFiles/lab.dir/verification.cpp.s

CMakeFiles/lab.dir/CS.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/CS.cpp.o: ../CS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/lab.dir/CS.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab.dir/CS.cpp.o -c /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/CS.cpp

CMakeFiles/lab.dir/CS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/CS.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/CS.cpp > CMakeFiles/lab.dir/CS.cpp.i

CMakeFiles/lab.dir/CS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/CS.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/CS.cpp -o CMakeFiles/lab.dir/CS.cpp.s

CMakeFiles/lab.dir/consolef.cpp.o: CMakeFiles/lab.dir/flags.make
CMakeFiles/lab.dir/consolef.cpp.o: ../consolef.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/lab.dir/consolef.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lab.dir/consolef.cpp.o -c /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/consolef.cpp

CMakeFiles/lab.dir/consolef.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab.dir/consolef.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/consolef.cpp > CMakeFiles/lab.dir/consolef.cpp.i

CMakeFiles/lab.dir/consolef.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab.dir/consolef.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/consolef.cpp -o CMakeFiles/lab.dir/consolef.cpp.s

# Object files for target lab
lab_OBJECTS = \
"CMakeFiles/lab.dir/main.cpp.o" \
"CMakeFiles/lab.dir/Pipe.cpp.o" \
"CMakeFiles/lab.dir/verification.cpp.o" \
"CMakeFiles/lab.dir/CS.cpp.o" \
"CMakeFiles/lab.dir/consolef.cpp.o"

# External object files for target lab
lab_EXTERNAL_OBJECTS =

lab: CMakeFiles/lab.dir/main.cpp.o
lab: CMakeFiles/lab.dir/Pipe.cpp.o
lab: CMakeFiles/lab.dir/verification.cpp.o
lab: CMakeFiles/lab.dir/CS.cpp.o
lab: CMakeFiles/lab.dir/consolef.cpp.o
lab: CMakeFiles/lab.dir/build.make
lab: CMakeFiles/lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable lab"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab.dir/build: lab
.PHONY : CMakeFiles/lab.dir/build

CMakeFiles/lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab.dir/clean

CMakeFiles/lab.dir/depend:
	cd /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug /Users/evgenijbelakov/Desktop/GitHub2/Belyakov_AS/lab/cmake-build-debug/CMakeFiles/lab.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab.dir/depend

