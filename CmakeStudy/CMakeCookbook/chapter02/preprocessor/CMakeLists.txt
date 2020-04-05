cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(preprocessor LANGUAGES CXX)

add_executable(hello-world hello-world.cpp)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_definitions(hello-world PUBLIC "IS_LINUX") 
elseif(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_definitions(hello-world PUBLIC "IS_MACOS") 
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_definitions(hello-world PUBLIC "IS_WINDOWS") 
endif()
