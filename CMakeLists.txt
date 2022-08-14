cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

project(sudoku)

set(target sudoku)

include_directories(include)

set(source 
    source/Sudoku.cpp
    source/Table.cpp
    source/Insert_command.cpp
    source/Erase_command.cpp
    source/main.cpp)


add_executable(${target} ${source})