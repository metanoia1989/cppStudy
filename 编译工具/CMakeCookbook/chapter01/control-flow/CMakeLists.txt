cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(control-flow LANGUAGES CXX)

add_library(geometry
    SHARED
    geometry_circle.cpp
    geometry_circle.hpp
    geometry_polygon.cpp
    geometry_polygon.hpp
    geometry_rhombus.cpp
    geometry_rhombus.hpp
    geometry_square.cpp
    geometry_square.hpp
)

target_compile_options(geometry
    PRIVATE -o3
)

list(
    APPEND source_with_lower_optimization
    geometry_circle.cpp
    geometry_rhombus.cpp
)

message(STATUS "Setting source properties using IN LISTS syntax.")
foreach(_source IN LISTS source_with_lower_optimization)
    set_source_files_properties(${_source} PROPERTIES COMPILE_FLAGS -o2)
    message(STATUS "Appending -02 flag for ${_source}")
endforeach()

message(STATUS "Querying sources properties using plain syntax.")
foreach(_source ${source_with_lower_optimization})
    get_source_file_property(_flags ${_source} COMPILE_FLAGS) 
    message(STATUS "Source ${_source} has the following extra COMPILE_FLAGS: ${_flags}")
endforeach()

add_executable(compute-areas compute-areas.cpp)

target_link_libraries(compute-areas geometry)