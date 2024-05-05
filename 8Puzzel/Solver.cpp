#include "Solver.h"

Solver::Solver(sf::Font& Font,Board& board)
{
	Squares.resize(9);
	TextInsideSquares.resize(9);
	textSettings(Font);
	getValues(board);
	createSolverBoard(Font);
}

Solver::~Solver()
{
}

void Solver::textSettings(sf::Font& Font)
{
	int index = 0;
	for (sf::Text text : TextInsideSquares)
	{
		text.setFillColor(sf::Color::White);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(20);
		text.setFont(Font);
		text.setPosition(sf::Vector2f(200 + index * (40), 600 + index * 40));
		index++;
	}
}

void Solver::getValues(Board& Board)
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->values[i][j] = Board.valueBoard[i][j];
		}
	}
}

void Solver::drawSolverBoard(sf::RenderWindow& window)
{
	for (auto& square : this->Squares)
	{
		window.draw(square.getRectangleShape());
	}

	for (sf::Text text : TextInsideSquares)
	{
		window.draw(text);
	}
}

void Solver::updateSolverBoard()
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->Squares[index].setSquareFillColor(sf::Color::Blue);
			this->TextInsideSquares[index].setString(std::to_string(this->values[i][j]-48));
			if (this->values[i][j] == '0')
			{
				this->Squares[index].setSquareFillColor(sf::Color::Red);
			}
			index++;
		}
	}
}

void Solver::createSolverBoard(sf::Font& Font)
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->Squares[index].setValue(this->values[i][j]);

			this->Squares[index].setSquarePosition(sf::Vector2f(200 + j * (40+5), 600+i*(40+5)));
			this->Squares[index].setSquareFillColor(sf::Color::Blue);
			this->Squares[index].setSquareSize(sf::Vector2f(40, 40));
			if (this->Squares[index].getValue() == '0')
			{
				this->Squares[index].setSquareFillColor(sf::Color::Red);
			}

			this->Squares[index].setSquareTextString(std::to_string(this->Squares[index].getValue()));
			this->Squares[index].setSquareTextFont(Font);
			
			this->TextInsideSquares[index].setFillColor(sf::Color::White);
			this->TextInsideSquares[index].setStyle(sf::Text::Bold);
			this->TextInsideSquares[index].setCharacterSize(20);
			this->TextInsideSquares[index].setFont(Font);
			this->TextInsideSquares[index].setPosition(sf::Vector2f(200 + j * (40 + 5), 600 + i * (40 + 5)));
			this->TextInsideSquares[index].setString(std::to_string(this->Squares[index].getValue()-48));
			std::cout << std::to_string(this->Squares[index].getValue() - 48) << "\n";

			index++;
		}
	}
}


