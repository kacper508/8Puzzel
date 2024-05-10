#include "Node.h"

bool Node::operator==(char values[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->valueBoard[i][j] != values[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

//void Node::operator=(char values[][BOARD_SIZE])
//{
//	for (int i = 0; i < BOARD_SIZE; i++)
//	{
//		for (int j = 0; j < BOARD_SIZE; j++)
//		{
//			this->valueBoard[i][j] = values[i][j];
//		}
//	}
//}

void Node::manhattanDistance()
{
	int p = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (BOARD_GOAL[i][j] != '0') {
				sf::Vector2i tempV = findPosition(BOARD_GOAL[i][j]);
				//std::cout << tempV.x << "|" << tempV.y << "\n";
				//std::cout << i << "|" << j << "\n";
				p += std::abs(i - tempV.x) + std::abs(j - tempV.y);
				//std::cout << "tttt" << "\n";
				//std::cout << BOARD_GOAL[i][j] << "|BG\n";
				//std::cout << this->valueBoard[i][j] << "|VB"  << "\n";
			}
		}
	}
	this->h_score = p;
	//std::cout << this->h_score << "\n";
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

sf::Vector2i Node::findPosition(char value)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->valueBoard[i][j] == value)
			{
				return sf::Vector2i(i,j);
			}
		}
	}
}

void Node::copyToAnotherArray(char values[][BOARD_SIZE])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			values[i][j] = this->valueBoard[i][j];
		}
	}
}

int Node::getH()
{
	return this->h_score;
}

void Node::setMove(char move)
{
	this->move = move;
}

void Node::copy(char values[][BOARD_SIZE])
{

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->valueBoard[i][j] = values[i][j];
		}
	}
}

Node* Node::getParent()
{
	return this->parent;
}

void Node::setG(int g)
{
	this->g_score = g;
}

void Node::setF()
{
	this->f_score = this->g_score + this->h_score;
}

int Node::getG()
{
	return this->g_score;
}

void Node::setParent(Node* parent)
{
	this->parent = parent;
}

void Node::display()
{
	std::cout << "qwe\n";
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << this->valueBoard[i][j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << "qwe\n";
}

int Node::getF()
{
	return this->f_score;
}

void Node::moveOnBoard(char direction)
{
	switch (direction)
	{
	case 'd':
		if (this->zeroPosition.y - 1 >= 0)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y - 1][this->zeroPosition.x];
			this->valueBoard[this->zeroPosition.y - 1][this->zeroPosition.x] = '0';
		}
		break;
	case 'u':
		if (this->zeroPosition.y + 1 <= 2)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y + 1][this->zeroPosition.x];
			this->valueBoard[this->zeroPosition.y + 1][this->zeroPosition.x] = '0';;
		}
		break;
	case 'l':
		if (this->zeroPosition.x + 1 <= 2)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y][this->zeroPosition.x + 1];
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x + 1] = '0';
		}
		break;
	case 'r':
		if (this->zeroPosition.x - 1 >= 0)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y][this->zeroPosition.x - 1];
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x - 1] = '0';
		}
		break;
	}
}

sf::Vector2i Node::getZero()
{
	return this->zeroPosition;
}

void Node::getValue(char values[][3])
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->valueBoard[i][j] = values[i][j];
		}
	}
}

