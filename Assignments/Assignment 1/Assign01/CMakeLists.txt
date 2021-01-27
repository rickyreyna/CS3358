cmake_minimum_required(VERSION 3.12)
project(Assign01StarterFiles)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assign01StarterFiles
        Assign01.cpp
        IntSet.cpp
        IntSet.h)
