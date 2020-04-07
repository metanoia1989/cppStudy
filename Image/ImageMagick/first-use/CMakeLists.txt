cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(magick-test LANGUAGES CXX)


option(ENTRY "程序入口文件" main.cpp)

message(STATUS "入口文件 ${ENTRY}")

add_executable(magick-test ${ENTRY})

target_compile_definitions(magick-test PUBLIC 
    -DMAGICKCORE_QUANTUM_DEPTH=16
    -DMAGICKCORE_HDRI_ENABLE=0
)
find_package(ImageMagick COMPONENTS Magick++)
target_include_directories(magick-test PUBLIC ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(magick-test PUBLIC ${ImageMagick_LIBRARIES})
