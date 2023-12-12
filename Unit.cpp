//
// Created by Rostyslav on 12.12.2023.
//
#include "Unit.h"

Unit::Unit(const std::string& id, int hp, int posX, int posY, int maxMove, int maxStep, int damage)
        : id(id), hp(hp), posX(posX), posY(posY), maxMove(maxMove), maxStep(maxStep), isDeadInside(false), damage(damage) {}
