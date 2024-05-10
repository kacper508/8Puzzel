#pragma once

#include "SFML/Graphics.hpp"

#include "Solver.h"
#include "Global.h"

#include <stdlib.h>

class Node
{
private:
	Node* parent;
	char move;
	int g_score = 0;
	int h_score = 0;
	int f_score;

	char valueBoard[BOARD_SIZE][BOARD_SIZE];

	sf::Vector2i zeroPosition;

public:
	// Check if the node with the same 
	bool operator==(char values[][BOARD_SIZE]);

	//void operator=(char values[][BOARD_SIZE]);
	void copy(char values[][BOARD_SIZE]);

	void setMove(char move);
	void setG(int g);
	void setF();
	void setParent(Node* parent);

	int getH();
	int getF();
	Node* getParent();

	int getG();

	sf::Vector2i findPosition(char value);

	void manhattanDistance();
	void updateZeroPosition();

	void getValue(char values[][BOARD_SIZE]);
	char (*getArray())[3]
		{
			return this->valueBoard;
		}

	void display();

	sf::Vector2i getZero();

	void moveOnBoard(char direction);

	char(*getValueBoard())[3] {
		return this->valueBoard;
		}

	void copyToAnotherArray(char values[][BOARD_SIZE]);
};

