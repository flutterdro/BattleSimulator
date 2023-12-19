//
// Created by Rostyslav on 11.12.2023.
//
#ifndef  BATTLESIMULATOR_H
#define BATTLESIMULATOR_H
#include <iostream>
#include "GameBoard.h"
#include "sstream"
#include "memory"

#include "Unit.h"


class BattleSimulator {
public:
    //there is no need to make it a pointer as well as allocating it on the heap
    GameBoard board;
    unsigned int currentTime;
    std::vector<std::unique_ptr<Unit>> units;

    BattleSimulator(int M, int N);

    void updateState(unsigned int newTime);

    Unit* getUnitAtPosition(int x, int y) {
        for (auto& unit : units) {
            if (unit->posX == x && unit->posY == y) {
                return unit.get();  // Returns a raw pointer to the unit
            }
        }
        return nullptr;
    }

    void setHeight(int row, int col, int height);

    void WriteState();

    void AddUnit(std::string unitType, std::string id, int x, int y);

    bool isPositionOccupied(int x, int y) const;

    void processCommand(const std::string& command);


};
#endif
