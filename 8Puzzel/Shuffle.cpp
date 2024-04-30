#include "Shuffle.h"


Shuffle::Shuffle()
{
}

Shuffle::~Shuffle()
{
}

void Shuffle::shuffleArray()
{
	for (int i = sizeof(this->valueBoard) / sizeof(this->valueBoard[0]) - 1; i > 0; --i)
	{
		int j = rand() % (i + 1);
		std::swap(this->valueBoard[i], this->valueBoard[j]);
	}

	for (int i = 0; i < 9; ++i) {
		std::cout << this->valueBoard[i] << " ";
		std::cout << std::endl;
	}

}

void Shuffle::copyValuesToBoard(Board &board)
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			board.valueBoard[i][j] = this->valueBoard[index];
			std::cout << "index = " << index << "\n";
			index++;
		}
	}
}

