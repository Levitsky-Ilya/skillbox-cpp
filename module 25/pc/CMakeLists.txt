cmake_minimum_required(VERSION 3.17)
project(pc)

set(CMAKE_CXX_STANDARD 14)

add_executable(pc main.cpp ram.cpp ram.h kbd.cpp kbd.h gpu.cpp gpu.h cpu.cpp cpu.h disk.cpp disk.h)