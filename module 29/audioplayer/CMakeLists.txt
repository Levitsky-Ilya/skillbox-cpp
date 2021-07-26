cmake_minimum_required(VERSION 3.17)
project(audioplayer)

set(CMAKE_CXX_STANDARD 14)

add_executable(audioplayer main.cpp Track.cpp Track.h Player.cpp Player.h)