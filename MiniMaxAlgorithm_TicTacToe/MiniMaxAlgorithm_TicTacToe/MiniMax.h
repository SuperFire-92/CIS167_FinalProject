#pragma once
#include <vector>
#include <iostream>
#include "Board.h"
using namespace std;

class MiniMax
{
private:

public:
	MiniMax();

	static vector<int> startMiniMax(Board b);
	static int miniMaxAlg(Board b, bool max);
};

