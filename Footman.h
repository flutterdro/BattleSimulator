//
// Created by Rostyslav on 12.12.2023.
//



#ifndef FOOTMAN_H
#define FOOTMAN_H
#include <string>

#include "BattleSimulator.h"


class Footman : public Unit {
public:
    Footman(const std::string& id, int posX, int posY)
        : Unit(id, 20, posX, posY, 1, 1, 1) {}

    void move(int x, int y, GameBoard* board) override;

    void attack(GameBoard* board) override;

    std::string getType() const override;
};

#endif