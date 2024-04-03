#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "Square.h"
#include "Global.h"
#include "Board.h"



Board::Board(sf::Font &Font)
{
	this->BoardShape.setFillColor(sf::Color::White);
	this->BoardShape.setPosition(155, 5);
	this->BoardShape.setSize(sf::Vector2f(490,490));
	createBoard(Font);
	updateZeroPosition();
}

void Board::moveValue(char moveDirection)
{
	switch (moveDirection)
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
			this->valueBoard[this->zeroPosition.y + 1][this->zeroPosition.x] = '0';
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

void Board::createBoard(sf::Font &Font)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->valueBoard[i][j] != '0')
			{
				Square* newSquare = new Square;
				newSquare->setValue(this->valueBoard[i][j]);
				newSquare->setSquarePosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE*BOARD_SIZE - SPACE_BETWEEN_SQUARES*2)/2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				newSquare->setSquareFillColor(sf::Color::Blue);
				newSquare->setSquareTextString(std::to_string(newSquare->getValue()));
				newSquare->setSquareTextFont(Font);
				newSquare->setSquareTextPosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				Squares.push_back(newSquare);
			}
			else if (this->valueBoard[i][j] == '0')
			{
				Square* newSquare = new Square;
				newSquare->setValue(this->valueBoard[i][j]);
				newSquare->setSquarePosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				newSquare->setSquareFillColor(sf::Color::Red);
				newSquare->setSquareTextString(std::to_string(newSquare->getValue()));
				newSquare->setSquareTextFont(Font);
				newSquare->setSquareTextPosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				Squares.push_back(newSquare);
			}
		}
	}
}

void Board::drawBoard(sf::RenderWindow& window)
{
	window.draw(this->BoardShape);
	for (auto square : this->Squares)
	{
		window.draw(square->getRectangleShape());
		//window.draw(square->getText());
	}
}

void Board::updateBoard()
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (valueBoard[i][j] != '0')
			{
				this->Squares[index]->setSquareFillColor(sf::Color::Blue);
				this->Squares[index]->setValue(this->valueBoard[i][j]);
				this->Squares[index]->setSquareTextString(std::to_string(valueBoard[i][j]));
			}
			else if (valueBoard[i][j] == '0')
			{
				this->Squares[index]->setSquareFillColor(sf::Color::Red);
				this->Squares[index]->setValue(this->valueBoard[i][j]);
				this->Squares[index]->setSquareTextString(std::to_string(valueBoard[i][j]));
			}
				index++;
		}
	}
}

bool Board::checkIfOver()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (this->valueBoard[i][j] == BOARD_GOAL[i][j])
			{
				continue;
			}
			else
			{
				return false;
			}
		}
	}
	return true;
}

void Board::updateZeroPosition()
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

Board::~Board()
{
	for (auto square : Squares)
	{
		delete square;
	}
}




// Uzupełnianie tablicy z wartościami przy ruchu

//FUnkcja checkPosiibleMove ma uzupełniać tablicę z ruchami na podstawie wartości

// Położenie 0 umieścić  w Board, żeby wiedzieć gdzie sięznajduje
//Po naciśnięciu najpierw sprawdza czy jest możliwośc ruchu w tą strone , ta wartość p w tablicy ruchów

