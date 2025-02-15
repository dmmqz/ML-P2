cmake_minimum_required(VERSION 3.25.1)
project(perceptronlearningrule)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    src/include
)

add_executable(main
    main.cpp
    src/perceptron.cpp
)
