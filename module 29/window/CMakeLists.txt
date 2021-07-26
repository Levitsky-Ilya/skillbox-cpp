cmake_minimum_required(VERSION 3.17)
project(window)

set(CMAKE_CXX_STANDARD 14)

add_executable(window main.cpp PixelCoords.cpp PixelCoords.h Window.cpp Window.h Screen.h)