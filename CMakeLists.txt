cmake_minimum_required(VERSION 3.28)
project(arcade_hub)

set(CMAKE_CXX_STANDARD 17)

add_executable(arcade_hub main.cpp
        Game.cpp
        Game.h
)
