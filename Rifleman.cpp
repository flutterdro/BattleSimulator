//
// Created by Rostyslav on 12.12.2023.
//
#include "Rifleman.h"

#include <queue>
#include <set>

#include "BattleSimulator.h"

Rifleman::Rifleman(const std::string& id, int posX, int posY)
        : Unit(id, 10, posX, posY, 2, 2, 3) {}

void Rifleman::move(int x, int y, GameBoard* board) {
    struct Node {
                int x, y, dist;
        };

        std::queue<Node> q;
        std::set<std::pair<int, int>> visited;
        q.push({posX, posY, 0});
        visited.insert({posX, posY});

        while (!q.empty()) {
                Node current = q.front();
                q.pop();

                // Check if we have reached the target position
                if (current.x == posX && current.y == posY) {
                        posX = posX;
                        posY = posY;
                        return; // Move successful
                }

                // Directions: up, right, down, left
                const int dx[] = {-1, 0, 1, 0};
                const int dy[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; ++i) {
                        int newX = current.x + dx[i];
                        int newY = current.y + dy[i];

                        // Check board boundaries
                        if (newX < 0 || newX >= board->M || newY < 0 || newY >= board->N)
                                continue;

                        // Check if already visited
                        if (visited.find({newX, newY}) != visited.end())
                                continue;

                        // Check if the position is occupied
                        if (BattleSimulator::isPositionOccupied(newX, newY))
                                continue;

                        // Check height difference constraint
                        if (abs(board->getHeight(newX, newY) - board->getHeight(current.x, current.y)) > maxStep)
                                continue;

                        // Check if within max move range
                        if (current.dist + 1 > maxMove)
                                continue;

                        // Add to queue and mark as visited
                        q.push({newX, newY, current.dist + 1});
                        visited.insert({newX, newY});
                }
        }

        // If we reach here, move failed
        isDeadInside = true;
}

void Rifleman::attack(GameBoard* board, const std::string& direction) {
}

std::string Rifleman::getType() const  {
    return "rifleman";
}
