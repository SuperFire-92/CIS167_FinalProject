#pragma once
class Board
{
private:
	//The board in its current state
	char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	//Whether or not the player started
	bool playerStart;
	//Whether or not its x's turn
	bool xTurn = true;
public:
	Board();
	Board(bool);
	void printBoard();
	int gameWon();
	void setPosition(int, int, char);
	void setPosition(int, int);
	bool makeMove(int, int);
	void setPlayerStart(bool);
	bool getPlayerStart();
	bool getTurn();
};
