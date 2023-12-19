//
// Created by Rostyslav on 12.12.2023.
//


#include "BattleSimulator.h"

#include <algorithm>
#include <concepts>
#include <ranges>
#include <memory>
#include "Unit.h"
#include "set"
#include "Knight.h"
#include "Rifleman.h"
#include "Footman.h"
#include <format>
#include <print>

template<typename T> 
    requires std::equality_comparable<T>
auto equal_to(T const& smth) {
    return [smth](auto&& x) { return x == smth; };
}

void BattleSimulator::AddUnit(std::string unitType, std::string id, int x, int y) {
    // if can't spawn - ignore
    if(isPositionOccupied(x, y))
        return;

    // outside from board
    if(x <= 0 || x > board.M || y <= 0 || y > board.N)
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


bool BattleSimulator::isPositionOccupied(int x, int y) const {
    auto to_tuple_from_ptr = [](const std::unique_ptr<Unit>& a) {
        return std::pair{a->posX, a->posY};
    };
    return std::ranges::any_of(units, equal_to(std::pair{x, y}), to_tuple_from_ptr);
}


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
                        unit->move(x, y, board, this);
                }
            } else if (cmd == "attack") {
                std::string id, direction;
                iss >> id >> direction;
                for(auto& unit: units) {
                    if(unit->id == id)
                        unit->attack(board, this, direction);
                }
                updateState(currentTime);
            } else if (cmd == "state") {
                updateState(currentTime);
                WriteState();
            }
            // if nothing from this - incorrect command
        }
    }
}

void BattleSimulator::WriteState() {
    // Sort the units by their positions (lexicographical order)
    auto to_tuple_from_ptr = [](const std::unique_ptr<Unit>& a) {
        return std::pair{a->posX, a->posY};
    };
    std::ranges::sort(units, std::less<std::pair<int, int>>{}, to_tuple_from_ptr);
    // Now print the sorted units
    for (const auto& unit : units) {
        std::string unitType = unit->getType();
        std::println("{} {} ({}, {})", unit->id, unitType, unit->posX, unit->posY, unit->hp);
    }
    std::println("---");
}



void BattleSimulator::updateState(unsigned newTime) {

    auto is_exhausted_hp = [](auto&& a) { return a->hp <= 0; };
    auto is_dead_inside = [](auto&& a) { return a->isDeadInside; };
    auto adjust_hp = [damage = newTime - currentTime](auto&& a) { a->hp -= damage; };

    std::ranges::for_each(units | std::views::filter(is_dead_inside), adjust_hp);
    auto elements_to_erase = std::ranges::remove_if(units, is_exhausted_hp);
    units.erase(elements_to_erase.begin(), elements_to_erase.end());
    currentTime = newTime; // Update the current time
}

void BattleSimulator::setHeight(int row, int col, int height) {
    board.setHeight(row, col, height);
}

BattleSimulator::BattleSimulator(int M, int N) 
    : board(M, N), currentTime(0) {}

