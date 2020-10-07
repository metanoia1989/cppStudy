cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(find-boost LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS filesystem)

add_executable(path-info path-info.cpp)

target_link_libraries(path-info
    PUBLIC 
        Boost::filesystem
)