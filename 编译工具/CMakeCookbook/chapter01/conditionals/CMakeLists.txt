cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(conditionals LANGUAGES CXX)

set(USE_LIBRARY ON)

message(STATUS "Compile sources into a library? ${USE_LIBRARY}")

set(BUILD_SHARED_LIBS OFF)

list(APPEND _sources Message.hpp Message.cpp)

if(USE_LIBRARY)
    # add_library 将会创建静态库，因为动态库被设置OFF
    add_library(message ${_sources})
    add_executable(hello-world hello-world.cpp)
    target_link_libraries(hello-world message)
else()
    add_executable(hello-world hello-world.cpp ${_sources})
endif()
