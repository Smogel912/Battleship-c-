#pragma once
#include <iostream>
using namespace std;


struct Ship{
    string name;
    int length;
    int x; 
    int y;
    bool sunk;
    //0 for horizontal, 1 for vert
    int orientation;
};

void ranPopulate(char board[10][10]);
void manPopulate(char board[10][10]);
void drawBoard(char board[10][10]);
void compTurn();
bool checkWin(int check);
void fire(string space);
