cmake_minimum_required(VERSION 3.0)
project(WhaleMarket)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set (CMAKE_C_COMPILER "/usr/bin/gcc")
set (CMAKE_CXX_COMPILER "/usr/bin/g++")

add_definitions("-Wall -g")

include_directories(include)

file(GLOB SOURCES "src/*.cpp"
            "src/tools/*.c"
            "src/User/*.cpp"
            "src/MyException/*.cpp"
            "src/Buffer/*.cpp"
            "src/DataFiles/*.cpp"
            "src/Goods/*.cpp"
            "src/Order/*.cpp"
            "src/Menu/*.cpp"
            )

add_executable(WhaleMarket ${SOURCES})