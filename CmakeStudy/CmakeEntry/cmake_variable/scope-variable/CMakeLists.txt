# Top Level

cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set(abc "123")

message("Top level scope (before): ${abc}")

add_subdirectory(boo)

message("Top Level scope (after): ${abc}")