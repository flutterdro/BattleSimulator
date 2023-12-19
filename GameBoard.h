//
// Created by Rostyslav on 11.12.2023.
//
#include <map>
#include <vector>


#ifndef GAMEBOARD_H
#define GAMEBOARD_H

class GameBoard {
public:
    int M, N;
    std::vector<std::vector<int>> heights;
    GameBoard(int m, int n) : M(m), N(n), heights(m, std::vector<int>(n)) {}

    void setHeight(int row, int col, int height)  {
        heights[row][col] = height;
    }

    int getHeight(int x, int y) const{
        if (x > 0 && x <= M && y > 0 && y <= N) {
            return heights[x-1][y-1];
        }
        return -1; // Neplatná pozice
    }

};


#endif