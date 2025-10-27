cmake_minimum_required(VERSION 4.0)
project(utilities C)

set(CMAKE_C_STANDARD 17)

# Include header files
include_directories(include)

# Gather all .c source files from src/ and its subfolders
file(GLOB SRC_FILES
        src/*.c
        src/*/*.c
)

# Create the static library
add_library(utilities STATIC ${SRC_FILES})

# Create the main executable
add_executable(main main.c)

# Link the main executable with the utilities library
target_link_libraries(main PRIVATE utilities)