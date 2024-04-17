//=========================================
//Name: Nicolaas Dyk
//Date: 04/01/2024
//Desc: Mini-Max Algorithm For Tic-Tac-Toe
//=========================================

#include <iostream>
#include <vector>
#include <string>
#include "Board.h"
#include "MiniMax.h"

using namespace std;

void playGame(Board board);
bool verifyProperPlayerStartInput(string input);
bool verifyProperMoveInput(string input, int& n, char& k);
string toLowerCase(string x);

int main()
{
    bool playerStart;
    string playerStartsInput;
    string restartInput;
    bool running = true;
    while (running)
    {
        system("CLS");
        do
        {
            cout << "Player Starts? (Y for yes, N for no): ";
            getline(cin, playerStartsInput);
        } while (!verifyProperPlayerStartInput(playerStartsInput));
        playerStart = (tolower(playerStartsInput[0]) == 'y' ? true : false);
        Board ticTacToe = Board(playerStart);

        playGame(ticTacToe);
        do
        {
            cout << endl << endl << "Play Again? (Y for yes, N for no): ";
            getline(cin, restartInput);
        } while (!verifyProperPlayerStartInput(restartInput));
        running = (tolower(restartInput[0]) == 'y' ? true : false);
    }

}

void playGame(Board board)
{
    while (board.gameWon() == -2)
    {
        //True when its the player's turn, false if it's the AI's turn
        bool curTurn = (board.getPlayerStart());
        curTurn = (board.getTurn() == false ? !curTurn : curTurn);
        int row;
        char col;

        //Players turn
        if (curTurn == true)
        {
            //Let the player play a turn
            //First display the board in its current state
            system("CLS");
            board.printBoard();

            string input;
            while (true)
            {
                cout << "Position: ";
                getline(cin, input);
                if (!verifyProperMoveInput(input, row, col))
                {
                    cout << "That is not a valid move (missing either a row or a column)" << endl;
                    continue;
                }
                if (board.makeMove(row, col - 97))
                {
                    break;
                }
                else
                {
                    cout << "Invalid Move" << endl;
                }
            }

        }
        //AI's turn
        else
        {
            vector<int> moves = MiniMax::startMiniMax(board);
            board.makeMove(moves.at(0), moves.at(1));
        }
    }
    system("CLS");
    board.printBoard();
    //This if statement case should never run but its here anyway
    if (board.gameWon() == -1)
    {
        cout << "Player has won!" << endl;
    }
    else if (board.gameWon() == 0)
    {
        cout << "It's a tie!" << endl;
    }
    else if (board.gameWon() == 1)
    {
        cout << "AI has won!" << endl;
    }
}

bool verifyProperPlayerStartInput(string input)
{
    if (input.size() != 1)
    {
        return false;
    }
    if (tolower(input[0]) != 'y' && tolower(input[0]) != 'n')
    {
        return false;
    }
    return true;
}

bool verifyProperMoveInput(string input, int& row, char& col)
{
    row = -1;
    col = ' ';
    input = toLowerCase(input);
    //Find ONE number and ONE letter
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] <= 'c' && input[i] >= 'a' && col == ' ')
        {
            col = input[i];
        }
        else if (input[i] <= '2' && input[i] >= '0' && row == -1)
        {
            row = input[i] - 48;
        }
    }
    if (row == -1 || col == ' ')
    {
        return false;
    }
    return true;
}

string toLowerCase(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = tolower(x[i]);
    }
    return x;
}