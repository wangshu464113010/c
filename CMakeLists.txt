cmake_minimum_required(VERSION 3.15)
project(project C)

set(CMAKE_C_STANDARD 99)

add_executable(project main.c list.h list.c json/json.h json/json.c data/data.h data/data.c base64/base64.c base64/base64.h file/copyfile.c file/copyfile.h xml/xml.c xml/xml.h map/map.h map/map.c tree/binary_tree.h tree/binary_tree.c)