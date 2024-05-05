#pragma once

#include "SFML/Graphics.hpp"

#include "Board.h"
#include "Node.h"

#include <iostream>
#include <list>


class Solver
{
private:
	char values[BOARD_SIZE][BOARD_SIZE];

	sf::RectangleShape Shape;

	std::vector<Square> Squares;
	std::vector<sf::Text> TextInsideSquares;

	// To solving puzzle
	//std::list<Node*> openList;
	std::list<Node*> closedList;

	std::list<Node*> solvedList;
public:
	Solver(sf::Font& Font, Board& board);
	~Solver();

	void solve(Board& Board, sf::RenderWindow& window, sf::Font& Font);

	void getValues(Board &Board);
	void createSolverBoard(sf::Font& Font);
	void drawSolverBoard(sf::RenderWindow& window);
	void updateSolverBoard();

	void textSettings(sf::Font& Font);

	// To solving
	void solvingPuzzle();
};

