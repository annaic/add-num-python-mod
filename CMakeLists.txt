cmake_minimum_required(VERSION 3.15...3.28)
project(add_numbers)
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

find_package(Python REQUIRED COMPONENTS Interpreter Development)
message(Python_INCLUDE_DIRS="${Python_INCLUDE_DIRS}")
message(Python_LIBRARIES="${Python_LIBRARIES}")


Python_add_library(add_numbers MODULE WITH_SOABI add_numbers.c)
set_target_properties(add_numbers PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY
        ${CMAKE_SOURCE_DIR})

install(TARGETS add_numbers DESTINATION .)





