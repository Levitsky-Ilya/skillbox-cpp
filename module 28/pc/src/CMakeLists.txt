cmake_minimum_required(VERSION 3.17)

add_executable(pc main.cpp
        ram.cpp ${MY_INCLUDE_DIR}/ram.h
        kbd.cpp ${MY_INCLUDE_DIR}/kbd.h
        gpu.cpp ${MY_INCLUDE_DIR}/gpu.h
        cpu.cpp ${MY_INCLUDE_DIR}/cpu.h
        disk.cpp ${MY_INCLUDE_DIR}/disk.h)
target_include_directories(pc PUBLIC ${CMAKE_SOURCE_DIR}/include)