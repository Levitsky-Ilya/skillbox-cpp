cmake_minimum_required(VERSION 3.17)
project(shared_ptr)

set(CMAKE_CXX_STANDARD 14)

add_executable(shared_ptr main.cpp Toy.cpp Toy.h shared_ptr_toy.h)