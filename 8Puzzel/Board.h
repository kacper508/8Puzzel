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
		{'1','2','3'},
		{'4','5','6'},
		{'7','0','8'},
	};

public:
	Board(sf::Font &Font);

	void moveValue(char moveDirection);

	void createBoard(sf::Font &Font);
	void drawBoard(sf::RenderWindow &window);
	void updateBoard();

	bool checkIfOver();

	void updateZeroPosition();

	~Board();
};

