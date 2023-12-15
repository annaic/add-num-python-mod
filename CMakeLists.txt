cmake_minimum_required(VERSION 3.16)
project(add_numbers)
set( PYTHON_EXECUTABLE /home/rajan/.pyenv/shims/python )
find_package(Python3 COMPONENTS Interpreter Development)
include_directories(${Python3_INCLUDE_DIRS})
message(Python3_INCLUDE_DIRS="${Python3_INCLUDE_DIRS}")
message(Python3_LIBRARIES="${Python3_LIBRARIES}")


set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_library(add_numbers MODULE add_numbers.c)
target_link_libraries(add_numbers ${Python3_LIBRARIES})


# Without this, the module will be called add_numbers.so instead of add_numbers.cpython-36m-darwin.so
set_target_properties(add_numbers PROPERTIES PREFIX "")
set_target_properties(add_numbers PROPERTIES SUFFIX ".so")

# Set the output directory for the build libraries
set_target_properties(add_numbers PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR})


