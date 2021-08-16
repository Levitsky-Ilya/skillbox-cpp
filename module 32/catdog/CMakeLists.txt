cmake_minimum_required(VERSION 3.17)
project(catdog)

set(CMAKE_CXX_STANDARD 14)

add_executable(catdog main.cpp Animal.cpp Animal.h)