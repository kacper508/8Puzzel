#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Board.h"
#include "Global.h"


class Shuffle
{
private:
	char valueBoard[BOARD_SIZE*BOARD_SIZE] = { '0','1','2','3','4','5','6','7','8' };
public:
	Shuffle();
	~Shuffle();

	void shuffleArray(Board& board);
	void copyValuesToBoard(Board &board);
};

