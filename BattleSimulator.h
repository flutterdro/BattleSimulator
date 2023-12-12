//
// Created by Rostyslav on 11.12.2023.
//

#include <iostream>
#include "GameBoard.h"
#include "sstream"
#include "memory"

class BattleSimulator {
public:
    static GameBoard* board;
    static unsigned int currentTime;
    static std::vector<std::unique_ptr<Unit>> units;

    static void initialize(int M, int N) {
        board = new GameBoard(M, N);
        currentTime = 0;
    }

    static void updateState(unsigned int newTime) {
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


    static void setHeight(int row, int col, int height) {
        board->setHeight(row, col, height);
    }

    static void WriteState() {
        for(auto& unit:units) {
            std::string unitType = unit->getType();
            std::cout << unit->id << " " << unitType << " (" << unit->posX << ", " << unit->posY << ") " << unit->hp << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    static void AddUnit(std::string unitType, std::string id, int x, int y);

    static bool isPositionOccupied(int x, int y) {
        for (const auto& unit : units) {
            if (unit->posX == x && unit->posY == y) {
                return true;
            }
        }
        return false;
    }

    static void processCommand(const std::string& command) {
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
                // Implement attack logic
            } else if (cmd == "state") {
                WriteState();
            }
            // if nothing from this - incorrect command
        }
    }


};
GameBoard* BattleSimulator::board = nullptr;
unsigned int BattleSimulator::currentTime = 0;
std::vector<std::unique_ptr<Unit>> BattleSimulator::units;
