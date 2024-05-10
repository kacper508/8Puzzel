#include "Shuffle.h"


Shuffle::Shuffle()
{
}

Shuffle::~Shuffle()
{
}

void Shuffle::shuffleArray(Board& Board)
{
	do
	{
		for (int i = sizeof(this->valueBoard) / sizeof(this->valueBoard[0]) - 1; i > 0; --i)
		{
			int j = rand() % (i + 1);
			std::swap(this->valueBoard[i], this->valueBoard[j]);
		}

	} while (!this->isSolvable());
	
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

int Shuffle::getInversionCount()
{
	int inversion = 0;
	for (int i = 0; i < BOARD_SIZE * BOARD_SIZE - 1; i++)
	{
		for (int j = i + 1; j < BOARD_SIZE * BOARD_SIZE; j++)
		{
			if (this->valueBoard[j]-48 && valueBoard[i]-48 && valueBoard[i]-48 > valueBoard[j]-48)
				inversion++;
		}
	}
	return inversion;
}

bool Shuffle::isSolvable()
{
	if (this->getInversionCount() % 2 == 0)
	{
		std::cout << "IS\n";
		return true;
	}
	return false;
}

