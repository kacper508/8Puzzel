#pragma once

#include "SFML/Graphics.hpp"

#include "Global.h"

class Node
{
private:
	Node* parent;
	char move;
	int g_score;
	int h_score;
	int f_score;

	char valueBoard[BOARD_SIZE][BOARD_SIZE];

	sf::Vector2i zeroPosition;

public:
	// Check if the node with the same 
	bool operator==(Node* node);
	void operator=(Node* node);


	sf::Vector2i findPosition();

	void manhattanDistance();
	void updateZeroPosition();

};

