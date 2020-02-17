cmake_minimum_required(VERSION 2.8)
project(foo NONE)

set(abc "123")

message("abc (before): ${abc}")
include("./modify-abc.cmake")
message("abc (after): ${abc}")

macro(modify_xyz)
    set(xyz "789") 
endmacro()

set(xyz "336")


message("xyz (before): ${xyz}")
modify_xyz()
message("xyz (after): ${xyz}")