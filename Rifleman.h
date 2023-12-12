//
// Created by Rostyslav on 12.12.2023.
//


#include <string>
#include "Unit.h"

#ifndef RIFLEMAN_H
#define RIFLEMAN_H
class Rifleman : public Unit {
public:
    Rifleman(const std::string& id, int posX, int posY);

    void move(int x, int y, GameBoard* board) override ;

    void attack(GameBoard* board) override;

    [[nodiscard]] std::string getType() const override;
};
#endif
