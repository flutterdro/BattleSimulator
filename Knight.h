//
// Created by Rostyslav on 12.12.2023.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Unit.h"

class Knight : public Unit {
public:
    Knight(const std::string& id, int posX, int posY)
        : Unit(id, 50, posX, posY, 5, 1, 5) {}

    void move(int x, int y, GameBoard* board) override {
        // Implement Knight-specific movement logic
    }

    void attack(GameBoard* board) override {
        // Implement Knight-specific attack logic
    }

    std::string getType() const override {
        return "knight";
    }
};


#endif //KNIGHT_H
