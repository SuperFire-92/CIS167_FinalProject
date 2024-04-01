#include "Board.h"
#include <iostream>
using namespace std;

void Board::printBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << (j < 2 ? " | " : "");
        }
        cout << endl << (i < 2 ? "- - - - -" : "") << endl;
    }
}

int Board::gameWon()
{
    //Return -1 if the player has won, 0 if a tie, 1 if the AI has won
    int playerOrAi = (playerStart ? 1 : -1);

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
    return 0;
}

void Board::setPlayerStart(bool t)
{
    playerStart = t;
}

void Board::setPosition(int row, int col, char x)
{
    board[row][col] = x;
}