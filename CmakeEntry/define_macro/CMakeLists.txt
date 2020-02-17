cmake_minimum_required(VERSION 3.9.1)

project(CMakeHello)

set(CMAKE_CXX_STANDARD 14)

# 默认系统 flags UNIX, WIN32, CYGWIN, APPLE
if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    add_definitions(-DCMAKEMACROSAMPLE="Apple MacOS")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    add_definitions(-DCMAKEMACROSAMPLE="Windows PC")
endif()

add_executable(cmake_hello main.cpp)
