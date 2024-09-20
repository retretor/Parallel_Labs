cmake_minimum_required(VERSION 3.29)
project(Parallel_Labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parallel_Labs main.cpp
        file_generator.cpp
        single_thread.cpp)
