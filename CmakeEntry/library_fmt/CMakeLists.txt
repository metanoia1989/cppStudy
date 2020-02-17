cmake_minimum_required(VERSION 3.9.1)

project(FmtDemo)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(fmt_demo main.cpp)

find_package(FMT REQUIRED)
target_link_libraries(fmt_demo fmt::fmt)
