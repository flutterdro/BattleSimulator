//
// Created by Rostyslav on 19.12.2023.
//
#include "Unit.h"
#include "GameBoard.h"
#include "BattleSimulator.h"

void Unit::move(int x, int y, const GameBoard& board, BattleSimulator* sim) {
    struct Node {
                int x, y, dist;
        };

        if(x == posX && y == posY) {
                return;
        }

        if(x > board.M || x <= 0 || y <= 0 || y>board.N) {
                isDeadInside = true;
                return;
        }
        std::queue<Node> q;
        std::set<std::pair<int, int>> visited;
        q.push({posX, posY, 0});
        visited.insert({posX, posY});
        if(sim->isPositionOccupied(x,y)) {
                isDeadInside = true;
                return;
        }
        while (!q.empty()) {
                Node current = q.front();
                q.pop();

                // Check if we have reached the target position
                if (current.x == x && current.y == y) {
                        posX = x;
                        posY = y;
                        return; // Move successful
                }

                // Directions: up, right, down, left
                constexpr int dx[] = {-1, 0, 1, 0};
                constexpr int dy[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; ++i) {
                        int newX = current.x + dx[i];
                        int newY = current.y + dy[i];

                        // Check board boundaries
                        if (newX <= 0 || newX > board.M || newY <= 0 || newY > board.N)
                                continue;

                        // Check if already visited
                        if (visited.find({newX, newY}) != visited.end())
                                continue;

                        // Check if the position is occupied
                        if (sim->isPositionOccupied(newX, newY))
                                continue;

                        // Check height difference constraint
                        if (abs(board.getHeight(newX, newY) - board.getHeight(current.x, current.y)) > maxStep)
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