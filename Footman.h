//
// Created by Rostyslav on 12.12.2023.
//


#include <string>

#include "BattleSimulator.h"


class Footman : public Unit {
public:
    Footman(const std::string& id, int posX, int posY)
        : Unit(id, 20, posX, posY, 1, 1, 1) {}

    void move(int x, int y, GameBoard* board) override {
        // Implement Knight-specific movement logic
        bool Failed = false;

        if(BattleSimulator::isPositionOccupied(x,y)) {

        }


        if(Failed)
            isDeadInside = true;
    }

    void attack(GameBoard* board) override {
        // Implement Knight-specific attack logic
    }

    std::string getType() const override {
        return "footman";
    }
};
