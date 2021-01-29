cmake_minimum_required(VERSION 2.6)
project(SDL2_App)

# includes cmake/FindSDL2.cmake
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(main.exe main.cpp Game.cpp)
SET(games 1, 2, 3, 4)
list(GET games 0 out)
MESSAGE(${out})
