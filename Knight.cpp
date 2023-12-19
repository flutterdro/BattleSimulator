//
// Created by Rostyslav on 12.12.2023.
//
#include "Knight.h"
#include "BattleSimulator.h"

#include <queue>


Knight::Knight(const std::string& id, int posX, int posY)
        : Unit(id, 50, posX, posY, 5, 1, 5) {}

void Knight::attack(const GameBoard& board, BattleSimulator* sim, const std::string& direction) {
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
        if(abs(board.getHeight(posX, posY) - board.getHeight(unit->posX, unit->posY)) > 1)
                return;
        int damageEnemy = damage + board.getHeight(posX, posY) - board.getHeight(unit->posX, unit->posY);
        damageEnemy = std::max(damageEnemy, 0);

        unit->hp-=damageEnemy;
}
