//=========================================
//Name: Nicolaas Dyk
//Date: 04/01/2024
//Desc: Mini-Max Algorithm For Tic-Tac-Toe
//=========================================

#include <iostream>
#include <vector>
#include "Board.h"

using namespace std;

int main()
{
    Board* ticTacToe = new Board();

    ticTacToe->setPosition(0, 2, 'X');
    ticTacToe->setPosition(1, 1, 'X');
    ticTacToe->setPosition(2, 0, 'X');

    ticTacToe->printBoard();

    cout << ticTacToe->gameWon();
}

