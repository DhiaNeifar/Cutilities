cmake_minimum_required(VERSION 4.0)
project(utilities C)

set(CMAKE_C_STANDARD 17)

add_library(utilities STATIC library.c)
add_executable(main main.c)
target_link_libraries(main PRIVATE utilities)