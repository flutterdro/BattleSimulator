//
// Created by Rostyslav on 12.12.2023.
//
#include "Footman.h"

void Footman::move(int x, int y, GameBoard* board) {
    // Implement Knight-specific movement logic
    bool Failed = false;

    if(BattleSimulator::isPositionOccupied(x,y))
        Failed = true;

    // we cant step
    if( abs(board->getHeight(x, y) - board->getHeight(posX, posY)) > maxStep )
        Failed = true;


    // can move only for one step
    if(!Failed) {
        if(x == posX && abs(y - posY) == 1) {
            posX = x; posY = y;
        }else if(y == posY && abs(x - posX) == 1) {
            posX = x; posY = y;
        }else
            Failed = true;
    }


    if(Failed)
        isDeadInside = true;
}

void Footman::attack(GameBoard* board, const std::string& direction) {
}

std::string Footman::getType() const  {
    return "footman";
}
