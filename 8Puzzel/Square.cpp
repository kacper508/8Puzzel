#include "Square.h"

Square::Square()
{
	this->SquareShape.setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));

	this->SquareText.setFillColor(sf::Color::White);
	this->SquareText.setCharacterSize(CHARACTER_SIZE);
	this->SquareText.setStyle(sf::Text::Bold);
}

sf::RectangleShape Square::getRectangleShape()
{
	return this->SquareShape;
}

sf::Text Square::getText()
{
	return this->SquareText;
}

void Square::drawSquare(sf::RenderWindow& window)
{
	window.draw(this->SquareShape);
	//window.draw(this->SquareText);
	window.draw(this->Shape);
}

char Square::getValue()
{
	return this->value;
}

void Square::setValue(char value)
{
	this->value = value;
}

void Square::setSquarePosition(sf::Vector2f Position)
{
	this->SquareShape.setPosition(Position);
}

void Square::setSquareFillColor(sf::Color Color)
{
	this->SquareShape.setFillColor(Color);
}

void Square::setSquareTextString(std::string TextValue)
{
	this->SquareText.setString(TextValue);
}

void Square::setSquareTextFont(sf::Font Font)
{
	this->SquareText.setFont(Font);
}

void Square::setSquareTextPosition(sf::Vector2f Position)
{
	this->SquareText.setPosition(Position);
}

void Square::setSquareSize(sf::Vector2f Size)
{
	this->SquareShape.setSize(Size);
}

void Square::setSprite(sf::IntRect(rect), sf::Vector2f(pos))
{
	this->Shape.setTextureRect(rect);
	this->Shape.setPosition(pos);
}

void Square::drawSprite(sf::RenderWindow& window)
{
	window.draw(this->Shape);
}


