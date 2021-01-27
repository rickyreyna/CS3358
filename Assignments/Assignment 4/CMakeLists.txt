cmake_minimum_required(VERSION 3.12)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(untitled1
        sequence.template
        sequence.h
        sequenceTest.cpp)
