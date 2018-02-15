//
//  minesweeper.cpp
//  Øving 6
//
//  Created by Magnus Pedersen on 26.02.14.
//  Copyright (c) 2014 Magnus Pedersen. All rights reserved.
//

#include "minesweeper.h"
#include <ctime>
using namespace std;
void Minesweeper::getInput()
{
    int a = -1;
    while (a < 2) // må være flere ruter enn 1 på brettet
    {
        cout << "Skriv inn ønsket høyde: " << endl;
        cin >> a;
    }
    height = a;
    
    a = -1;
    while (a < 2) // må være flere ruter enn 1 på brettet
    {
        cout << "Skriv inn ønsket bredde: " << endl;
        cin >> a;
    }
    width = a;
    a = -1;
    while (a < 1 || a > width*height / 2) //må være flere miner enn a = 0
    {
        cout << "Skriv inn antall miner: " << endl;
        cin >> a;
    }
    mines = a;
}

void Minesweeper::makeBoard()
{
    board = new int*[height];
    mask = new int*[height];
    for (int i = 0; i < height; i++)
    {
        board[i] = new int[width];
        mask[i] = new int[width];
        for (int j = 0; j < width; j++)
        {
            board[i][j] = 0;
            mask[i][j] = 0;
        }
    }
}

void Minesweeper::placeMines()
{
	int randH, randW;
    for (int i = 0; i < mines; i++)
	{
		do
        {
			randH = rand() % height;
			randW = rand() % width;
		} while (board[randH][randW] == -1);
        
		board[randH][randW] = -1;
        
		for (int i = randH - 1; i < randH + 2; i++)
		{
			for (int j = randW - 1; j < randW + 2; j++)
			{
				if (!(i == randH && j == randW) && i >= 0 && i < height && j >= 0 && j < width && board[i][j] != -1)
				{
					board[i][j]++;
				}
			}
		}
	}
}

void Minesweeper::setFlag(int rad, int kolonne)
{
    if (kolonne >= 0 && rad >= 0  && kolonne < width && rad < height)
    {
        if (mask[rad][kolonne] == 2)
        {
            mask[rad][kolonne] = 0;
        }
        else if (mask[rad][kolonne] == 0)
        {
            mask[rad][kolonne] = 2;
        }
    }
}

bool Minesweeper::openSquare(int rad, int kolonne)
{
    if (kolonne >= 0 && rad >= 0  && kolonne < width && rad < height)
    {
        if (board[rad][kolonne] == -1)
        {
            return true;
        }
        open++;
        mask[rad][kolonne] = 1;
    }
    return false;
}

void Minesweeper::printBoard(bool showMines)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (showMines && board[i][j] == -1)
            {
                cout << "x";
                continue;
            }
            if (mask[i][j] == 0)
            {
                cout << '#';
            }
            else if (mask[i][j] == 1)
            {
                if (board[i][j] == 0)
                {
                    cout << ' ';
                }
                else
                {
                    cout << board[i][j];
                }
            }
            else if (mask[i][j] == 2)
            {
                cout << 'f';
            }
        }
        cout << endl;
    }
}
void Minesweeper::cleanUpMemory()
{
	for (int i = 0; i < height; i++)
	{
		delete[] board[i];
		delete[] mask[i];
        
	}
	delete[] board;
	delete[] mask;
    
	mask = nullptr;
	board = nullptr;
}
void Minesweeper::play()
{
    Minesweeper m;
    string svar = "";
    srand(static_cast<unsigned>(time(0)));
    getInput();
    makeBoard();
    placeMines();
    printBoard(true);
    cout << endl << endl;
    bool loss = false;
    while (!loss)
    {
        printBoard(loss);
        char c;
        cout << "Trykk 'f' for å flagge, eller 'o' for å åpne et felt. Trykk x for å avslutte: ";
        cin >> c;
        int rad;
        int kolonne;
        switch (toupper(c))
        {
            case 'F':
                cout << "Hvilket felt vil du flagge? (rad kolonne)" << endl;
                cin >> rad >> kolonne;
                setFlag((rad-1),(kolonne-1));
                break;
            case 'O':
                cout << "Hvilket felt vil du åpne? (rad kolonne)" << endl;
                cin >> rad >> kolonne;
                loss = openSquare((rad-1),(kolonne-1));
                break;
            case 'X':
                return;
            default:
                continue;
        }
        if (open == width * height - mines)
        {
            cout << "Du vant! Vil du spille en gang til? (ja/nei)" << endl;
            cin >> svar;
            if (svar == "ja")
            {
                m.play();
            }
            else {return;}
        }
    }
    printBoard(true);
    cout << "Du har tapt. Vil du spille en gang til? (ja/nei)" << endl;
    cin >> svar;
    if (svar == "ja")
    {
        m.play();
    }
    cleanUpMemory();
    
}
