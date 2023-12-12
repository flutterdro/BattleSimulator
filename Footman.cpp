//
// Created by Rostyslav on 12.12.2023.
//
#include "Footman.h"

void Footman::move(int x, int y, GameBoard* board) {
    // Implement Knight-specific movement logic
    bool Failed = false;

    if(BattleSimulator::isPositionOccupied(x,y)) {
        Failed = true;
    }
    if(!Failed) {

    }


    if(Failed)
        isDeadInside = true;
}

void Footman::attack(GameBoard* board) {
}

std::string Footman::getType() const  {
    return "footman";
}
