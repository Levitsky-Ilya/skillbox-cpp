cmake_minimum_required(VERSION 3.17)
project(kino)

set(CMAKE_CXX_STANDARD 17)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(kino main.cpp)

target_link_libraries(kino PRIVATE nlohmann_json::nlohmann_json)