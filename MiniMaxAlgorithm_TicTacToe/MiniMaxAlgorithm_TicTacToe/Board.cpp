#include "Board.h"
#include <iostream>
using namespace std;

Board::Board()
{

}

Board::Board(bool t)
{
    playerStart = t;
}

void Board::printBoard()
{
    cout << "    A   B   C" << endl << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i << "   ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << (j < 2 ? " | " : "");
        }
        cout << endl << (i < 2 ? "   ---+---+---" : "") << endl;
    }
}

/// <summary>
/// 
/// </summary>
/// <returns>-2 if the game is not complete, -1 if the player has won, 0 if a tie, 1 if the AI has won</returns>
int Board::gameWon()
{
    //Stores whether or not the player started as a positive or negative number to add or subtract to the inARow variable
    int playerOrAi = (playerStart ? -1 : 1);
    //Stores whether or not the board is current full
    bool boardFull = true;

    //Horizontal wins
    for (int i = 0; i < 3; i++)
    {
        int inARow = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ')
            {
                inARow = (board[i][j] == 'X' ? inARow + playerOrAi : inARow - playerOrAi);
            }
            else
            {
                boardFull = false;
                break;
            }
            if (inARow / 3 != 0)
            {
                return inARow / 3;
            }
        }
    }
    //Vertical wins
    for (int j = 0; j < 3; j++)
    {
        int inARow = 0;
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] != ' ')
            {
                inARow = (board[i][j] == 'X' ? inARow + playerOrAi : inARow - playerOrAi);
            }
            else
            {
                break;
            }
            if (inARow / 3 != 0)
            {
                return inARow / 3;
            }
        }
    }
    //Diagonal wins
    int inARow = 0;
    int inARowN = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][i] != ' ')
        {
            inARow = (board[i][i] == 'X' ? inARow + playerOrAi : inARow - playerOrAi);
        }
        if (inARow / 3 != 0)
        {
            return inARow / 3;
        }
        if (board[i][2 - i] != ' ')
        {
            inARowN = (board[i][2 - i] == 'X' ? inARowN + playerOrAi : inARowN - playerOrAi);
        }
        if (inARowN / 3 != 0)
        {
            return inARowN / 3;
        }
    }
    if (boardFull)
        return 0;
    else
        return -2;
}

void Board::setPlayerStart(bool t)
{
    playerStart = t;
}


void Board::setPosition(int row, int col, char x)
{
    board[row][col] = x;
}

/// <summary>
/// 
/// </summary>
/// <param name="row"></param>
/// <param name="col"></param>
void Board::setPosition(int row, int col)
{
    board[row][col] = (xTurn ? 'X' : 'O');
    xTurn = !xTurn;
}

bool Board::makeMove(int row, int col)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = (xTurn ? 'X' : 'O');
        xTurn = !xTurn;
        return true;
    }
    return false;
}

bool Board::getPlayerStart()
{
    return playerStart;
}

//Returns true if the current turn is X, false is the current turn is O
bool Board::getTurn()
{
    return xTurn;
}