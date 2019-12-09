cmake_minimum_required(VERSION 2.8)

project(demo2)

# 加入一个配置头文件，用于处理CMake对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_BINARY_DIR}/config.h"
)

# 是否还是用自己的 math_functions 库
option(USE_MYMATH 
    "Use provided math implementation" OFF)

# 是否加入 math_functions 库
if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)   
    set (EXTRA_LIBS ${EXTRA_LIBS} math_functions) # 将 math_functions 加入静态链接库
endif(USE_MYMATH)


# 查找当前目录下的所有源文件
aux_source_directory(. DIR_SRCS)

# 指定生成目标 
add_executable(Demo ${DIR_SRCS})

# 添加链接库
target_link_libraries(Demo ${EXTRA_LIBS})