cmake_minimum_required(VERSION 3.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 23)


project(MyProject)

include_directories(inc)


file(GLOB SRC src/*.cpp src/*.c)

add_executable(poly_sim ${SRC})

