cmake_minimum_required(VERSION 3.20)
project(lab)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab main.cpp verification.h Pipe.cpp Pipe.h verification.cpp CS.cpp CS.h consolef.h consolef.cpp Filter.h Filter.cpp GTS.cpp GTS.h)
