#include <SFML/Graphics.hpp>

#include <vector>
#include <iostream>

#include "Square.h"
#include "Global.h"
#include "Board.h"



Board::Board(sf::Font &Font, sf::Texture& texture)
{
	this->BoardShape.setFillColor(sf::Color::White);
	this->BoardShape.setPosition(155, 5);
	this->BoardShape.setSize(sf::Vector2f(490,490));
	createBoard(Font, texture);
	Texts.resize(9);

	createTexts(Font);
	updateZeroPosition();
}

bool Board::moveValue(char moveDirection)
{
	switch (moveDirection)
	{
	case 'd':
		if (this->zeroPosition.y - 1 >= 0)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y - 1][this->zeroPosition.x];
			this->valueBoard[this->zeroPosition.y - 1][this->zeroPosition.x] = '0';
			return true;
		}
		break;
	case 'u':
		if (this->zeroPosition.y + 1 <= 2)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y + 1][this->zeroPosition.x];
			this->valueBoard[this->zeroPosition.y + 1][this->zeroPosition.x] = '0';
			return true;
		}
		break;
	case 'l':
		if (this->zeroPosition.x + 1 <= 2)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y][this->zeroPosition.x + 1];
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x + 1] = '0';
			return true;
		}
		break;
	case 'r':
		if (this->zeroPosition.x - 1 >= 0)
		{
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x] = this->valueBoard[this->zeroPosition.y][this->zeroPosition.x - 1];
			this->valueBoard[this->zeroPosition.y][this->zeroPosition.x - 1] = '0';
			return true;
		}
		break;
	}
	return false;
}

void Board::createBoard(sf::Font &Font, sf::Texture& texture)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			Square* newSquare = new Square;
			newSquare->setValue(this->valueBoard[i][j]);
			newSquare->setSquarePosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
			if (this->valueBoard[i][j] != '0')
			{
				newSquare->setSquareFillColor(sf::Color::Blue);
			}
			else if (this->valueBoard[i][j] == '0')
			{
				newSquare->setSquareFillColor(sf::Color::Red);
			}
			newSquare->setSquareTextString(std::to_string(newSquare->getValue() - 48));
			newSquare->setSquareTextFont(Font);
			newSquare->setSquareTextPosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
			Squares.push_back(newSquare);

			switch (this->valueBoard[i][j])
			{
			case '1':
				newSquare->setSprite(texture, sf::IntRect(0, 0, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "1\n";
				break;
			case '2':
				newSquare->setSprite(texture, sf::IntRect(150, 0, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "2\n";
				break;
			case '3':
				newSquare->setSprite(texture, sf::IntRect(300, 0,150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "3\n";
				break;
			case '4':
				newSquare->setSprite(texture, sf::IntRect(0, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "4\n";
				break;
			case '5':
				newSquare->setSprite(texture, sf::IntRect(150, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "5\n";
				break;
			case '6':
				newSquare->setSprite(texture, sf::IntRect( 300, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "6\n";
				break;
			case '7':
				newSquare->setSprite(texture, sf::IntRect(0, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "7\n";
				break;
			case '8':
				newSquare->setSprite(texture, sf::IntRect(150, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "8\n";
				break;
			case '0':
				newSquare->setSprite(texture, sf::IntRect(300, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "0\n";
				break;
			}
		}
	}
}

void Board::drawBoard(sf::RenderWindow& window)
{
	window.draw(this->BoardShape);
	for (auto square : this->Squares)
	{
		square->drawSquare(window);
		square->drawSprite(window);
	}

	for (sf::Text text : Texts)
	{
		window.draw(text);
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
				this->Squares[index]->setSquareTextString(std::to_string(valueBoard[i][j]-48));

				this->Texts[index].setString(std::to_string(valueBoard[i][j]-48));
			}
			else if (valueBoard[i][j] == '0')
			{
				this->Squares[index]->setSquareFillColor(sf::Color::Red);
				this->Squares[index]->setValue(this->valueBoard[i][j]);
				this->Squares[index]->setSquareTextString(std::to_string(valueBoard[i][j]-48));

				this->Texts[index].setString(std::to_string(valueBoard[i][j]-48));
			}

				switch (this->valueBoard[i][j])
			{
			case '1':
				this->Squares[index]->updateSprite(sf::IntRect(0, 0, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "1\n";
				break;
			case '2':
				this->Squares[index]->updateSprite(sf::IntRect(150, 0, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "2\n";
				break;
			case '3':
				this->Squares[index]->updateSprite(sf::IntRect(300, 0,150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "3\n";
				break;
			case '4':
				this->Squares[index]->updateSprite(sf::IntRect(0, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "4\n";
				break;
			case '5':
				this->Squares[index]->updateSprite(sf::IntRect(150, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "5\n";
				break;
			case '6':
				this->Squares[index]->updateSprite(sf::IntRect( 300, 150, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "6\n";
				break;
			case '7':
				this->Squares[index]->updateSprite(sf::IntRect(0, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "7\n";
				break;
			case '8':
				this->Squares[index]->updateSprite(sf::IntRect(150, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "8\n";
				break;
			case '0':
				this->Squares[index]->updateSprite(sf::IntRect(300, 300, 150, 150), sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
				std::cout << "0\n";
				break;
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

void Board::createTexts(sf::Font& Font)
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->Texts[index].setFont(Font);
			this->Texts[index].setString(std::to_string(valueBoard[i][j]-48));
			this->Texts[index].setFillColor(sf::Color::White);
			this->Texts[index].setPosition(sf::Vector2f(((WINDOW_WIDTH - SQUARE_SIZE * BOARD_SIZE - SPACE_BETWEEN_SQUARES * 2) / 2) + j * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES), SPACE_BETWEEN_SQUARES + i * (SQUARE_SIZE + SPACE_BETWEEN_SQUARES)));
			index++;
		}
	}
}

bool Board::getPauseValue()
{
	return this->pause;
}

void Board::setPauseValue(bool value)
{
	this->pause = value;
}
