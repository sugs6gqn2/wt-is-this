# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

# Set the project name to the desired name
project(MyCppCompiler)

# Specify the source files
set(SOURCES
    src/main.cpp
    # Add other source files here
)

# Add an executable target
add_executable(MyExecutable ${SOURCES})

# Specify the output directory for the binary
set_target_properties(MyExecutable PROPERTIES 
    OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)