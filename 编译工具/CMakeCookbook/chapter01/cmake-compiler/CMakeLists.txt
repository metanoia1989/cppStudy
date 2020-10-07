cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(cmake-compiler LANGUAGES C CXX)

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
    message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}") 
    message(STATUS "Is the C++ from GUN? ${CMAKE_COMPILER_IS_GUNCXX}")
    message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()

message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if(CMAKE_C_COMPILER_LOADED)
    message(STATUS "The C compiler ID is: ${CMAKE_CXX_COMPILER_ID}") 
    message(STATUS "Is the C from GUN? ${CMAKE_COMPILER_IS_GUNCXX}")
    message(STATUS "The C compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()
