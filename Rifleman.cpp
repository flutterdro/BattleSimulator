//
// Created by Rostyslav on 12.12.2023.
//
#include "Rifleman.h"
#include "BattleSimulator.h"

Rifleman::Rifleman(const std::string& id, int posX, int posY)
        : Unit(id, 10, posX, posY, 2, 2, 3) {}


void Rifleman::attack(GameBoard* board, BattleSimulator* sim, const std::string& direction){
        int atPosX = 0;
        int atPosY = 0;

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

        int startX = atPosX + posX;
        int startY = atPosY + posY;

        while (startX > 0 && startX <= board->M && startY > 0 && startY <= board->N) {
                auto unit = sim->getUnitAtPosition(startX, startY);
                if (unit != nullptr) {
                        int heightDifference = board->getHeight(posX, posY) - board->getHeight(unit->posX, unit->posY);
                        int damageEnemy = damage + heightDifference; // Assuming 3 is the base damage of Rifleman
                        damageEnemy = std::max(damageEnemy, 0);
                        unit->hp -= damageEnemy;
                        break;
                }
                startX += atPosX;
                startY += atPosY;
        }

}

std::string Rifleman::getType() const  {
    return "rifleman";
}
