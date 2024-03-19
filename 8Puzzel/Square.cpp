#include <SFML/Graphics.hpp>

#include "Square.h"
#include "Global.h"

Square::Square()
{
	this->SquareShape.setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
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


