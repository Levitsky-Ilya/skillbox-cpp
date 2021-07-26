cmake_minimum_required(VERSION 3.17)
project(cellphone)

set(CMAKE_CXX_STANDARD 14)

add_executable(cellphone main.cpp Contact.cpp Contact.h Cellphone.cpp Cellphone.h)