cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(bf_heap_sort)

add_definitions(-g -O2 -Wall -std=c99)
include_directories(.)

add_library(${PROJECT_NAME} HeapSort.c)
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)
