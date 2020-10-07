cmake_minimum_required(VERSION 3.9.1)

project(CMakeHello)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# set(SOURCES main.cpp 
#     lib/math/operations.cpp
#     lib/math/operations.hpp)
aux_source_directory(. SOURCES)
aux_source_directory(lib/math LIB)

add_executable(cmake_hello ${SOURCES} ${LIB})