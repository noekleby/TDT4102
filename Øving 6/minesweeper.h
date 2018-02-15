//
//  minesweeper.h
//  Øving 6
//
//  Created by Magnus Pedersen on 26.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#ifndef ___ving_6__minesweeper__
#define ___ving_6__minesweeper__

#include <iostream>
class Minesweeper
{
private:
    int height;
    int width;
    int mines;
    int open;
    int **board;
    int **mask; //ruter spilleren har åpnet
    
    void placeMines(); // mine representeres med verdien -1
    void cleanUpMemory(); //delete[] på alle pekerne -> huske å lage
    void getInput();
    void makeBoard();
    void setFlag(int rad, int kolonne);
    bool openSquare(int rad, int kolonne); // sette mask til 1, hvis mine, return true
    void printBoard(bool);
public:
    void play();
};
#endif /* defined(___ving_6__minesweeper__) */
