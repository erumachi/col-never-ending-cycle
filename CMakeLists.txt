cmake_minimum_required(VERSION 3.1)

project(never_ending_cycle)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SOURCES
    src/main.c
    src/cyclic_dequeue.c)

include_directories(include)

add_executable(never_ending_cycle ${SOURCES})
