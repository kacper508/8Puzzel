#include <SFML/Graphics.hpp>

#include <vector>

#include "Square.h"
#include "Global.h"
#include "Board.h"


Board::Board(sf::Font &Font)
{
	
	createBoard(Font);
}

void Board::moveValue(char moveDirection)
{
	sf::Vector2i zeroPosition;

}

void Board::createBoard(sf::Font &Font)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (int(this->valueBoard[i][j]) % 48 > 0)
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
			else
			{
				Square* newSquare = new Square;
				newSquare->setValue(this->valueBoard[i][j]);
				newSquare->setSquarePosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				newSquare->setSquareFillColor(sf::Color::Black);
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
	for (auto square : this->Squares)
	{
		window.draw(square->getRectangleShape());
		//window.draw(square->getText());
	}
}

Board::~Board()
{
	for (auto square : Squares)
	{
		delete square;
	}
}
