cmake_minimum_required (VERSION 2.8)

# projectname is the same as the main-executable
project(sort_tests)

add_subdirectory(HeapSort)
add_definitions(-g -O2 -Wall -std=c99)
include_directories(.)

aux_source_directory(unit_test DIR_SRC)
add_executable(${PROJECT_NAME} ${DIR_SRC})
target_link_libraries(${PROJECT_NAME} 
    check m rt pthread subunit bf_heap_sort
)
