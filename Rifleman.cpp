//
// Created by Rostyslav on 12.12.2023.
//
#include "Rifleman.h"

Rifleman::Rifleman(const std::string& id, int posX, int posY)
        : Unit(id, 10, posX, posY, 2, 2, 3) {}

void Rifleman::move(int x, int y, GameBoard* board) {
}

void Rifleman::attack(GameBoard* board) {
}

std::string Rifleman::getType() const  {
    return "rifleman";
}
