//
// Created by Rostyslav on 11.12.2023.
//

#include <iostream>
#include "GameBoard.h"
#include "sstream"
#include "memory"
#include "Knight.h"
#include "Rifleman.h"
#include "Footman.h"

#ifndef BATTLESIMULATOR_H
#define BATTLESIMULATOR_H
class BattleSimulator {
public:
    static GameBoard* board;
    static unsigned int currentTime;
    static std::vector<std::unique_ptr<Unit>> units;

    static void initialize(int M, int N);

    static void updateState(unsigned int newTime);


    static void setHeight(int row, int col, int height);

    static void WriteState();

    static void AddUnit(std::string unitType, std::string id, int x, int y);

    static bool isPositionOccupied(int x, int y);

    static void processCommand(const std::string& command);


};
#endif
