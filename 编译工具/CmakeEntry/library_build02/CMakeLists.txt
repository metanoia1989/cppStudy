cmake_minimum_required(VERSION 3.9.1)

project(CMakeHello)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

message("程序二进制目录：${CMAKE_BINARY_DIR}")

add_library(math SHARED lib/math/operations.cpp)
# add_library(math STATIC lib/math/operations.cpp)

aux_source_directory(. SOURCES)

add_executable(cmake_hello ${SOURCES})

target_link_libraries(cmake_hello math)