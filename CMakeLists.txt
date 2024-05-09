cmake_minimum_required(VERSION 3.26)
project(Arcasde_hub)
set(CMAKE_EXE_LINKER_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)

add_executable(Arcasde_hub main.cpp
        Game.cpp
        Game.h)
