cmake_minimum_required(VERSION 2.6)

project(helloworld)

# 设置makefile生成器
set(CMAKE_GENERATOR "Unix Makefiles")

# 设置库文件存放路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)

# 设置执行文件存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

# 获取当前目录及子目录（递归获取），添加到头文件搜索路径
function(include_sub_directories_recursively root_dir) 
    # 当前路径是一个目录吗，是则加入包含目录
    if (IS_DIRECTORY ${root_dir}) 
        message("include dir: " ${root_dir})
        include_directories(${root_dir})
    endif()

    # 获得当前目录下的所有文件
    file(GLOB ALL_SUB RELATIVE ${root_dir} ${root_dir}/*)
    foreach(sub ${ALL_SUB})
        if (IS_DIRECTORY ${root_dir}/${sub})    # 子目录递归调用
            include_sub_directories_recursively(${root_dir}/${sub})
        endif()
    endforeach()
endfunction()

# 项目的所有目录都为头文件搜索路径
include_sub_directories_recursively(${PROJECT_SOURCE_DIR})

# 添加库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/build/lib)

# 添加子目录
add_subdirectory(src)
add_subdirectory(test)

# 设置安装目录
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
        