cmake_minimum_required(VERSION 3.15)


set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -pedantic")

project(StringTest)

add_executable(StringPgm
    test/main.cpp
    src/String.cpp
    include/String.h
)

include_directories(StringTest "./src" "./include")

project(String) 

add_library(String SHARED
    src/String.cpp
    include/String.h
)

include_directories(StringTest "./src" "./include")
