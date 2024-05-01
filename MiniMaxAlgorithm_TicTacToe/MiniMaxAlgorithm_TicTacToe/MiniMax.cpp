#include "MiniMax.h"

MiniMax::MiniMax()
{

}

/// <summary>
/// Finds the best possible move for the AI to use
/// </summary>
/// <returns>a vector with the row and col</returns
vector<int> MiniMax::startMiniMax(Board b)
{
	int bestScore = -999;
	int score = -999;
	Board copy;
	vector<int> moves = { -1,-1 };
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			copy = b;
			if (copy.makeMove(r, c))
			{
				score = miniMaxAlg(copy, false);
				if (score > bestScore)
				{
					bestScore = score;
					moves.at(0) = r;
					moves.at(1) = c;
					
				}
				
			}
			
		}
	}
	return moves;
}

int MiniMax::miniMaxAlg(Board b, bool max)
{
	//Check for gameover
	if (b.gameWon() != -2)
	{
		return b.gameWon();
	}
	
	//Ai turn
	if (max)
	{
		int bestScore = -999;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				//Make move in each spot, see outcomes
				Board copy = b;
				int score;
				if (copy.makeMove(r, c))
				{
					score = miniMaxAlg(copy, !max);
					if (score > bestScore)
					{
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}

	//Player turn
	else
	{
		int bestScore = 999;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				//Make move in each spot, see outcomes
				Board copy = b;
				int score;
				if (copy.makeMove(r, c))
				{
					score = miniMaxAlg(copy, !max);
					if (score < bestScore)
					{
						bestScore = score;
					}
				}
			}
		}
		return bestScore;
	}
}