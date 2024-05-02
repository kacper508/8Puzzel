#include "Shuffle.h"


Shuffle::Shuffle()
{
}

Shuffle::~Shuffle()
{
}

void Shuffle::shuffleArray(Board& Board)
{
	for (int i = sizeof(this->valueBoard) / sizeof(this->valueBoard[0]) - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		std::swap(this->valueBoard[i], this->valueBoard[j]);
	}
	copyValuesToBoard(Board);
}

void Shuffle::copyValuesToBoard(Board &board)
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board.valueBoard[i][j] = this->valueBoard[index];
			index++;
		}
	}
}

