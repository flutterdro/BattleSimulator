//
// Created by Rostyslav on 12.12.2023.
//
#include "GameBoard.h"

GameBoard::GameBoard(int m, int n) : M(m), N(n), heights(m, std::vector<int>(n)) {}

void GameBoard::setHeight(int row, int col, int height)  {
    heights[row][col] = height;
}

int GameBoard::getHeight(int x, int y)  {
    if (x >= 0 && x < M && y >= 0 && y < N) {
        return heights[x][y];
    }
    return -1; // Neplatná pozice
}
