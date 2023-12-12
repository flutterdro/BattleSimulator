//
// Created by Rostyslav on 12.12.2023.
//


#include "BattleSimulator.h"
#include "Knight.h"
#include "Rifleman.h"

void BattleSimulator::AddUnit(std::string unitType, std::string id, int x, int y) {
    // if can't spawn - ignore
    if(isPositionOccupied(x, y))
        return;

    // outside from board
    if(x < 0 || x > board->M || y < 0 || y > board->N)
        return;

    // same iв
    for(auto& unit:units) {
        if(unit->id == id)
            return;
    }


    if(unitType == "knight") {
        units.emplace_back(std::make_unique<Knight>(id, x, y));
    }else if(unitType == "rifleman") {
        units.emplace_back(std::make_unique<Rifleman>(id, x, y));
    }else if(unitType == "footman") {
        //units.emplace_back(std::make_unique<Footman>(id, x, y));
    }
}
