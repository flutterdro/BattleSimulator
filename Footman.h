//
// Created by Rostyslav on 12.12.2023.
//



#ifndef FOOTMAN_H
#define FOOTMAN_H
#include <string>

#include "Unit.h"


class Footman : public Unit {
public:
    Footman(const std::string& id, int posX, int posY)
        : Unit(id, 20, posX, posY, 1, 1, 1) {}

    void attack(GameBoard* board, BattleSimulator* sim, const std::string& direction) override;

    std::string getType() const override;
};

#endif
