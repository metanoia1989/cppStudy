cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(object-lib LANGUAGES CXX)

# 从源代码生成对象库
add_library(message-objs 
    OBJECT 
        Message.hpp
        Message.cpp)

add_library(message-shared 
    SHARED
        $<TARGET_OBJECTS:message-objs>)
set_target_properties(message-shared 
    PROPERTIES 
        OUTPUT_NAME "message")

add_library(message-static
    STATIC
        $<TARGET_OBJECTS:message-objs>)
set_target_properties(message-static
    PROPERTIES 
        OUTPUT_NAME "message")

add_executable(hello-world hello-world.cpp)

target_link_libraries(hello-world message-static)