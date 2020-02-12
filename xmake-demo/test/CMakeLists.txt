# project
cmake_minimum_required(VERSION 3.13.0)

# target
add_executable(test "")
set_target_properties(test PROPERTIES OUTPUT_NAME "test")
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY "build/mingw/x86_64/release")
if(MSVC)
    target_compile_options(test PRIVATE $<$<CONFIG:Release>:-Ox -fp:fast>)
else()
    target_compile_options(test PRIVATE -O3)
endif()
target_sources(test PRIVATE
    src/main.c
)

