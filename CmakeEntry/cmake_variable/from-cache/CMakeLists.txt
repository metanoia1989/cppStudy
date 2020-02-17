cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set(a "789" CACHE STRING "")
set(a "123")

message("Regular variable from current scope: ${a}")
unset(a)
message("Cache variable if regular not found: ${a}")