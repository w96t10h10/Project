cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Function.cpp
        Function.h
        main.cpp
        Node.h)

add_executable(Project ${SOURCE_FILES})