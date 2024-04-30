#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "Global.h"


class Score
{
private:
	int scoreValue;
	sf::Text Text;
	sf::RectangleShape Shape;
	sf::Text TextValue;
public:

	Score(sf::Font& Font);
	~Score();

	void reset();
	void draw(sf::RenderWindow& window);
	void update();

};

