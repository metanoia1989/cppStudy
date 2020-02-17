cmake_minimum_required(VERSION 3.9.1)

project(CMakeHello)

set(CMAKE_CXX_STANDARD 14)

# 默认系统 flags UNIX, WIN32, CYGWIN, APPLE
if(UNIX) 
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(WIN32)
    message("This is a Windows System")
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES Darwin)
    message("This is a ${CMAKE_SYSTEM_NAME} system")
elseif(${CMAKE_SYSTEM_NAME} MATCHES Windows)
    message("This is a Window System")
endif()
