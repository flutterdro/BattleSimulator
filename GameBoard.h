//
// Created by Rostyslav on 11.12.2023.
//
#include <map>
#include <vector>

#include "Unit.h"

class GameBoard {
public:
    int M, N;
    std::vector<std::vector<int>> heights;
    GameBoard(int m, int n) : M(m), N(n), heights(m, std::vector<int>(n)) {}

    void setHeight(int row, int col, int height) {
        heights[row][col] = height;
    }

    void UpdateGame() {

    }

    int getHeight(int x, int y) {
        if (x >= 0 && x < M && y >= 0 && y < N) {
            return heights[x][y];
        }
        return -1; // Neplatná pozice
    }


};