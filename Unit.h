//
// Created by Rostyslav on 12.12.2023.
//

#ifndef UNIT_H
#define UNIT_H
#include <string>
#include "queue"
#include <set>

class BattleSimulator;
class GameBoard;

class Unit {
public:
    std::string id;
    int hp;
    int posX, posY; // Position
    int maxMove, maxStep; // Movement capabilities
    bool isDeadInside;
    int damage;
    Unit(const std::string& id, int hp, int posX, int posY, int maxMove, int maxStep, int damage)
        : id(id), hp(hp), posX(posX), posY(posY), maxMove(maxMove), maxStep(maxStep), isDeadInside(false), damage(damage) {}

    virtual ~Unit() = default;

    void move(int x, int y, GameBoard* board, BattleSimulator* sim); // Pure virtual function for movement
    virtual void attack(GameBoard* board, BattleSimulator* sim, const std::string& direction) = 0; // Pure virtual function for attack
    [[nodiscard]] virtual std::string getType() const = 0;
};




#endif //UNIT_H
