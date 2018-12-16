cmake_minimum_required(VERSION 3.13)
project(game-maths)

set(CMAKE_CXX_STANDARD 14)

add_executable(game-maths
        main.cpp
        vectors.h
        vectors.cpp
        matrices.h
        matrices.cpp)
