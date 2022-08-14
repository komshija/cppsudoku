cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

project(sudoku)

set(target sudoku)

include_directories(include)
include_directories(include/game_loop_cmds)

set(source 
    source/Sudoku.cpp
    source/Table.cpp
    source/Insert_command.cpp
    source/game_loop_cmds/Game_loop.cpp
    source/game_loop_cmds/Show_main_menu_command.cpp
    source/game_loop_cmds/Handle_main_menu_input_command.cpp
    source/main.cpp
    )

add_executable(${target} ${source})