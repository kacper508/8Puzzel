#pragma once
#include "Global.h"
#include "Square.h"

class Board
{
private:
	bool pause = true;
	
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

	bool getPauseValue();
	void setPauseValue(bool value);
	
	bool moveValue(char moveDirection);

	void createBoard(sf::Font& Font);
	void drawBoard(sf::RenderWindow &window);
	void updateBoard();

	bool checkIfOver();

	void updateZeroPosition();

	~Board();

	friend class Shuffle;
	friend class Solver;

};

