#include "Solver.h"

Solver::Solver(sf::Font& Font)
{
	Squares.resize(9);
	TextInsideSquares.resize(9);
	textSettings(Font);
	createSolverBoard(Font);

}

Solver::~Solver()
{
}

void Solver::textSettings(sf::Font& Font)
{
	int index = 0;
	for (auto text : TextInsideSquares)
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

	//for (int i = 0; i < BOARD_SIZE; i++)
	//{
	//	for (int j = 0; j < BOARD_SIZE; j++)
	//	{
	//		std::cout << this->values[i][j] << " ";
	//	}
	//	std::cout << "\n";
	//}
}

void Solver::drawSolverBoard(sf::RenderWindow& window)
{
	//for (auto& text : this->TextInsideSquares)
	//{
	//	window.draw(text);
	//	std::string t = text.getString();
	//	std::cout << t << "  |";
	//}
	//std::cout << "\n ";

	for (auto& square : this->Squares)
	{
		window.draw(square.getRectangleShape());
		//window.draw(square.getText());
	}

}

void Solver::updateSolverBoard()
{
	int index = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			this->TextInsideSquares[index].setString(this->values[i][j]);
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

			this->Squares[index].setSquareTextString(std::to_string(this->Squares[index].getValue()));
			this->Squares[index].setSquareTextFont(Font);
			//this->Squares[index].setTen(sf::Vector2f(200 + j * (40), 600 + i * 40));

			this->TextInsideSquares[index].setString(std::to_string(this->Squares[index].getValue()-48));


			index++;
		}
	}
}


