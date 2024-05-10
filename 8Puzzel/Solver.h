#pragma once

#include "SFML/Graphics.hpp"

#include "Board.h"
#include "Node.h"

#include <iostream>
#include <list>
#include <queue>
#include <map>

#include <iterator>

class Node;

class Solver
{
private:
	char values[BOARD_SIZE][BOARD_SIZE];
	int order;

	sf::RectangleShape Shape;

	std::vector<Square> Squares;
	std::vector<sf::Text> TextInsideSquares;

	// To solving puzzle
	std::list<Node*> openList;
	std::list<Node*> closedList;

	std::list<Node*> solvedList;
	std::vector<Node*> solved;
public:
	Solver(sf::Font& Font, Board& board);
	~Solver();

	void solve(Board& Board, sf::RenderWindow& window, sf::Font& Font);

	void getValues(Board &Board);
	void createSolverBoard(sf::Font& Font);
	void drawSolverBoard(sf::RenderWindow& window);
	void updateSolverBoard(Board& board);

	void textSettings(sf::Font& Font);

	// Function updating values for solver from list solved
	void updateValues(Board& board);
	void getVal(char values[][3]);

	// To solving
	//void solvingPuzzle();

	void changeOrder(char z);
};


void createChildren(Node* node, std::list<Node*> &open, std::list<Node*> &closed);

bool compareArrays(const char arr1[3][3], const char arr2[3][3]);

bool processNode(std::list<Node*>& nodeList, const char targetData[3][3]);

void sortList(std::list<Node*>& nodeList);