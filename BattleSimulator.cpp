//
// Created by Rostyslav on 12.12.2023.
//


#include "BattleSimulator.h"

#include <algorithm>


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
        units.emplace_back(std::make_unique<Footman>(id, x, y));
    }
}


bool BattleSimulator::isPositionOccupied(int x, int y) {
    for (const auto& unit : units) {
        if (unit->posX == x && unit->posY == y) {
            return true;
        }
    }
    return false;
}

GameBoard* BattleSimulator::board = nullptr;
unsigned int BattleSimulator::currentTime = 0;
std::vector<std::unique_ptr<Unit>> BattleSimulator::units;

void BattleSimulator::processCommand(const std::string& command) {
    {
        std::istringstream iss(command);
        std::string cmd;
        while (iss >> cmd) {
            if (cmd == "spawn") {
                std::string unitType, id;
                int x, y;
                iss >> unitType >> id >> x >> y;
                AddUnit(unitType, id, x, y);
            } else if (cmd == "move") {
                std::string id;
                int x, y;
                iss >> id >> x >> y;
                // Implement move logic
                for(auto& unit: units) {
                    if(unit->id == id)
                        unit->move(x, y, board);
                }
            } else if (cmd == "attack") {
                std::string id, direction;
                iss >> id >> direction;
                for(auto& unit: units) {
                    if(unit->id == id)
                        unit->attack(board, direction);
                }
            } else if (cmd == "state") {
                WriteState();
            }
            // if nothing from this - incorrect command
        }
    }
}

void BattleSimulator::WriteState() {
    // Sort the units by their IDs
    std::sort(units.begin(), units.end(), [](const std::unique_ptr<Unit>& a, const std::unique_ptr<Unit>& b) {
        return a->id < b->id;
    });

    // Now print the sorted units
    for (const auto& unit : units) {
        std::string unitType = unit->getType();
        std::cout << unit->id << " " << unitType << " (" << unit->posX << ", " << unit->posY << ") " << unit->hp << std::endl;
    }
    std::cout << "---" << std::endl;
}

void BattleSimulator::updateState(unsigned newTime) {
    auto it = units.begin();
    while (it != units.end()) {
        auto& unit = *it;
        if (unit->isDeadInside) {
            int damage = newTime - currentTime;
            unit->hp -= damage;

            if (unit->hp <= 0) {
                // The unit is dead, remove it from the vector
                it = units.erase(it); // erase returns the iterator to the next element
                continue; // Skip the increment of the iterator
            }
        }
        ++it; // Increment the iterator
    }
    currentTime = newTime; // Update the current time
}

void BattleSimulator::setHeight(int row, int col, int height) {
    board->setHeight(row, col, height);
}

void BattleSimulator::initialize(int M, int N) {
    board = new GameBoard(M, N);
    currentTime = 0;
}
