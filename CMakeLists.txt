cmake_minimum_required(VERSION 3.23)
project(Test C)

set(CMAKE_C_STANDARD 99)

add_executable(Test main.c libs/data_structures/vector/vector.h libs/data_structures/vector/vector.c)
