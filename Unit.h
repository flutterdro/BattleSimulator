//
// Created by Rostyslav on 12.12.2023.
//

#ifndef UNIT_H
#define UNIT_H
#include <string>
#include "GameBoard.h"

class Unit {
public:
    std::string id;
    int hp;
    int posX, posY; // Position
    int maxMove, maxStep; // Movement capabilities
    bool isDeadInside;
    int damage;
    Unit(const std::string& id, int hp, int posX, int posY, int maxMove, int maxStep, int damage);

    virtual ~Unit() = default;

    virtual void move(int x, int y, GameBoard* board) = 0; // Pure virtual function for movement
    virtual void attack(GameBoard* board, const std::string& direction) = 0; // Pure virtual function for attack
    virtual std::string getType() const = 0;
};




#endif //UNIT_H
