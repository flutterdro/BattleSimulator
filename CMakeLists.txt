cmake_minimum_required(VERSION 3.27)
project(BattleSimulator)

set(CMAKE_CXX_STANDARD 23)

add_executable(BattleSimulator main.cpp
        GameBoard.h
        BattleSimulator.h
        Unit.h
        Knight.h
        Rifleman.h
        Footman.h
        BattleSimulator.cpp
        Footman.cpp
        Knight.cpp
        Rifleman.cpp
        Unit.cpp
)
