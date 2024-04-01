#pragma once
class Board
{
private:
	char board[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	bool playerStart;
public:

	void setPlayerStart(bool);
	void printBoard();
	int gameWon();
	void setPosition(int, int, char);
};
