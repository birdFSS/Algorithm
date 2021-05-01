cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(get_min_k_num)

add_definitions(-g -Wall -std=c99)
include_directories(../../sort_all/HeapSort)

add_executable(${PROJECT_NAME} MinK.c ../../sort_all/HeapSort/HeapSort.c)
