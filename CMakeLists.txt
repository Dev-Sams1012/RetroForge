cmake_minimum_required(VERSION 3.20)
project(RetroForge LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(core)
add_subdirectory(cli)
# add_subdirectory(gui)