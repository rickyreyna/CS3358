cmake_minimum_required(VERSION 3.12)
project(Assignment_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_3
        Assign03.cpp
        Sequence.cpp
        Assign03Auto.cpp
        Sequence.h)
