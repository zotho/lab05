cmake_minimum_required(VERSION 3.8)
project(lab05)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Map.cpp Algorythm.cpp)
add_executable(binary ${SOURCE_FILES})