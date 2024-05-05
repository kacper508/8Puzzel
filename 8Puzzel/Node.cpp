#include "Node.h"

bool Node::operator==(Node* node)
{

	return false;
}

void Node::manhattanDistance()
{
	this->h_score = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (BOARD_GOAL[i][j] != 0) {
				sf::Vector2i tempV = findPosition();
				h_score += abs(i - tempV.x) + abs(j - tempV.y);
			}
		}
	}
}

void Node::updateZeroPosition()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->valueBoard[i][j] == '0')
			{
				this->zeroPosition.x = j;
				this->zeroPosition.y = i;
			}
		}
	}
}

sf::Vector2i Node::findPosition()
{
	return sf::Vector2i();
}