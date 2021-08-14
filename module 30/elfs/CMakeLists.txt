cmake_minimum_required(VERSION 3.17)
project(elfs)

set(CMAKE_CXX_STANDARD 17)

add_executable(elfs main.cpp House.cpp House.h Tree.cpp Tree.h TreeHelper.cpp TreeHelper.h)