cmake_minimum_required(VERSION 3.9.1)

project(CMakeHello)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

message("程序二进制目录：${CMAKE_BINARY_DIR}")

aux_source_directory(. SOURCES)
add_executable(cmake_hello ${SOURCES})

add_subdirectory(lib/math)

find_package(Boost 1.66)
if (Boost_FOUND)
    message ("Boost Found")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(cmake_hello ${Boost_LIBRARIES})
elseif(NOT Boost_FOUND) 
    error("Boost Not Found")
    include_directories("F:\\Program\\msys64\\mingw64\\include\\boost")
    link_directories("F:\\Program\\msys64\\mingw64\\lib")
    target_link_libraries(cmake_hello Boost)
endif()

target_link_libraries(cmake_hello math)