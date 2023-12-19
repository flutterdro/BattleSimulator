//
// Created by Rostyslav on 12.12.2023.
//

#ifndef KNIGHT_H
#define KNIGHT_H
#include "Unit.h"

class Knight : public Unit {
public:
    Knight(const std::string& id, int posX, int posY);

    void attack(GameBoard* board, BattleSimulator* sim, const std::string& direction) override;

    std::string getType() const override {
        return "knight";
    }
};


#endif //KNIGHT_H
