//=========================================
//Name: Nicolaas Dyk
//Date: 04/01/2024
//Desc: Mini-Max Algorithm For Tic-Tac-Toe
//=========================================

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "Board.h"
#include "MiniMax.h"

using namespace std;

void playGame(Board board);
bool verifyProperPlayerStartInput(string input);
bool verifyProperPlayerRestartInput(string input);
bool verifyProperMoveInput(string input, int& n, char& k);
string toLowerCase(string x);

int main()
{
    //Only set to true to avoid the IDE yelling at me
    bool playerStart = true;
    //Two inputs from the player to get if the player is starting and if the player wants to play again
    string playerStartsInput;
    string restartInput;
    //If the game should loop, switches to false once the player types N to end the game
    bool running = true;
    while (running)
    {
        system("CLS");
        //Get player start
        do
        {
            cout << "Player Starts? (Y for yes, N for no, R for random): ";
            getline(cin, playerStartsInput);
        } while (!verifyProperPlayerStartInput(playerStartsInput));
        //Select if the player starts or not
        if (tolower(playerStartsInput[0]) == 'y')
        {
            playerStart = true;
        }
        else if (tolower(playerStartsInput[0]) == 'n')
        {
            playerStart = false;
        }
        else if (tolower(playerStartsInput[0]) == 'r')
        {
            srand(time(0));
            playerStart = (rand() % 2 == 0 ? true : false);
        }
        Board ticTacToe = Board(playerStart);

        //Play the game
        playGame(ticTacToe);

        //See if the player wishes to play again
        do
        {
            cout << endl << endl << "Play Again? (Y for yes, N for no): ";
            getline(cin, restartInput);
        } while (!verifyProperPlayerRestartInput(restartInput));
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
            //Get inputs from player until the player gives a valid move
            while (true)
            {
                cout << "Position: ";
                getline(cin, input);
                if (!verifyProperMoveInput(input, row, col))
                {
                    cout << "That is not a valid move (missing either a row or a column)" << endl;
                    cout << "Format should be A0 or 0A" << endl;
                    continue;
                }
                if (board.makeMove(row, col - 97))
                {
                    break;
                }
                else
                {
                    cout << "Invalid Move - Position Taken" << endl;
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
    //Display who won
    //This -1 case should never run but its here anyway
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

//Ensures that the provided player input is valid for deciding if the player starts
bool verifyProperPlayerStartInput(string input)
{
    if (input.size() != 1)
    {
        return false;
    }
    if (tolower(input[0]) != 'y' && tolower(input[0]) != 'n' && tolower(input[0]) != 'r')
    {
        return false;
    }
    return true;
}

//Ensures that the provided player input is valid for deciding if the game should continue
bool verifyProperPlayerRestartInput(string input)
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

//Makes sure the move the user provided is valid (only has 1 (0,1,2) and 1 (A,B,C)).
//Can have an insane amount of characters in between as long as they aren't 0,1,2,A,B,C.
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

//Turns a string to all lowercase characters
string toLowerCase(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        x[i] = tolower(x[i]);
    }
    return x;
}