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
    GameBoard(int m, int n);

    void setHeight(int row, int col, int height);

    int getHeight(int x, int y);


};


#endif