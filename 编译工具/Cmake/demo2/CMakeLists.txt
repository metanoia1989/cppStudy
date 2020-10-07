cmake_minimum_required(VERSION 2.8)

project(demo2)

# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})