//
// Created by Rostyslav on 12.12.2023.
//
#include "Footman.h"
#include "BattleSimulator.h"

void Footman::attack(GameBoard* board, BattleSimulator* sim, const std::string& direction) {
    int atPosX = posX;
    int atPosY = posY;

    if(direction == "up")
        atPosX--;
    else if(direction == "down")
        atPosX++;
    else if(direction == "right")
        atPosY ++;
    else if(direction == "left")
        atPosY--;
    else
        return;

    auto unit = sim->getUnitAtPosition(atPosX, atPosY);
    if(unit == nullptr) {
        return;
    }

    if(board->getHeight(posX, posY) - board->getHeight(unit->posX, unit->posY) != 0)
        return;

    int damageEnemy = damage + board->getHeight(posX, posY) - board->getHeight(unit->posX, unit->posY);
    damageEnemy = std::max(damageEnemy, 0);

    unit->hp-=damageEnemy;
}

std::string Footman::getType() const  {
    return "footman";
}
