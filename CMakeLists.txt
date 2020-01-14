cmake_minimum_required(VERSION 3.15)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c list.h list.c json/json.h json/json.c data/data.h data/data.c)