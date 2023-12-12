//
// Created by Rostyslav on 12.12.2023.
//
#include "Knight.h"

Knight::Knight(const std::string& id, int posX, int posY)
        : Unit(id, 50, posX, posY, 5, 1, 5) {}

void Knight::move(int x, int y, GameBoard* board) {
}

void Knight::attack(GameBoard* board) {
}
