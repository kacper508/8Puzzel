#pragma once

#include <SFML/Graphics.hpp>

#include "Global.h"

class Square
{
private:

	sf::Sprite Shape;

	sf::RectangleShape SquareShape;
	sf::Text SquareText;

	char value;
public:
	Square();

	sf::RectangleShape getRectangleShape();
	sf::Text getText();

	char getValue();
	void setValue(char value);

	void setSquarePosition(sf::Vector2f Position);
	void setSquareFillColor(sf::Color Color);
	void setSquareTextString(std::string TextValue);
	void setSquareTextFont(sf::Font Font);
	void setSquareTextPosition(sf::Vector2f Position);
};

