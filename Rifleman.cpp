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

        if(x == posX && y == posY) {
                return;
        }

        if(x > board->M || x <= 0 || y <= 0 || y>board->N) {
                isDeadInside = true;
                return;
        }
        std::queue<Node> q;
        std::set<std::pair<int, int>> visited;
        q.push({posX, posY, 0});
        visited.insert({posX, posY});
        if(BattleSimulator::isPositionOccupied(x,y)) {
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
                const int dx[] = {-1, 0, 1, 0};
                const int dy[] = {0, 1, 0, -1};

                for (int i = 0; i < 4; ++i) {
                        int newX = current.x + dx[i];
                        int newY = current.y + dy[i];

                        // Check board boundaries
                        if (newX <= 0 || newX > board->M || newY <= 0 || newY > board->N)
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
        int atPosX = 0;
        int atPosY = 0;

        if(direction == "up")
                atPosX--;
        else if(direction == "down")
                atPosX++;
        else if(direction == "right")
                atPosY ++;
        else if(direction == "left")
                atPosY--;
        else
                return;

        int startX = atPosX + posX;
        int startY = atPosY + posY;

        while (startX > 0 && startX <= board->M && startY > 0 && startY <= board->N) {
                auto unit = BattleSimulator::getUnitAtPosition(startX, startY);
                if(unit == nullptr) {
                        startX += atPosX;
                        startY += atPosY;
                        continue;
                }
                int damageEnemy = damage + board->getHeight(posX, posY) - board->getHeight(unit->posX, unit->posY);
                damageEnemy = std::max(damageEnemy, 0);

                unit->hp-=damageEnemy;
                break;
        }

}

std::string Rifleman::getType() const  {
    return "rifleman";
}
