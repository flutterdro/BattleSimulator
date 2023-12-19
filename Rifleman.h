//
// Created by Rostyslav on 12.12.2023.
//

#ifndef RIFLEMAN_H
#define RIFLEMAN_H
#include <string>
#include "Unit.h"

class Rifleman : public Unit {
public:
    Rifleman(const std::string& id, int posX, int posY);

    void attack(const GameBoard& board, BattleSimulator* sim, const std::string& direction) override;

    [[nodiscard]] std::string getType() const override;
};
#endif
