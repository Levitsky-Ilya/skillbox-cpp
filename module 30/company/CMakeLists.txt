cmake_minimum_required(VERSION 3.17)
project(company)

set(CMAKE_CXX_STANDARD 14)

add_executable(company main.cpp Employees.cpp Employees.h EmployeesHelper.cpp EmployeesHelper.h)