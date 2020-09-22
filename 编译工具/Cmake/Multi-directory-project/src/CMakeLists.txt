aux_source_directory(. DIR_SRC)

# 添加子目录
add_subdirectory(hello)
add_subdirectory(world)

# 执行文件
add_executable(hello_prj ${DIR_SRC})
target_link_libraries(hello_prj hello_lib world_lib)