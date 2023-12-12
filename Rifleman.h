//
// Created by Rostyslav on 12.12.2023.
//

#include <string>
#include "Unit.h"


class Rifleman : public Unit {
public:
    Rifleman(const std::string& id, int posX, int posY)
        : Unit(id, 10, posX, posY, 2, 2, 3) {}

    void move(int x, int y, GameBoard* board) override {
        // Implement Knight-specific movement logic
    }

    void attack(GameBoard* board) override {
        // Implement Knight-specific attack logic
    }

    std::string getType() const override {
        return "rifleman";
    }
};
