#pragma once
#include "Global.h"
#include "Square.h"

class Board
{
private:
	sf::RectangleShape BoardShape;

	std::vector<Square*> Squares;

	sf::Vector2i zeroPosition;

	char possibleMove[BOARD_SIZE][BOARD_SIZE];
	char valueBoard[BOARD_SIZE][BOARD_SIZE] = {
		{'6','8','5'},
		{'1','3','7'},
		{'0','2','4'},
	};

public:
	Board(sf::Font &Font);

	void moveValue(char moveDirection);

	void createBoard(sf::Font &Font);
	void drawBoard(sf::RenderWindow &window);
	void updateBoard();

	~Board();
};

