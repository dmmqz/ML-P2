cmake_minimum_required(VERSION 3.25.1)
project(perceptronlearningrule)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src/include
)

add_executable(test
    test/test.cpp
    test/parsedata.cpp
    src/perceptron.cpp
)

target_compile_definitions(test PRIVATE PROJ_ROOT="${CMAKE_CURRENT_SOURCE_DIR}")
