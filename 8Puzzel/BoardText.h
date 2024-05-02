#pragma once

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>

class BoardText
{
private:
	std::vector<sf::Text> text;
public:
	BoardText();
	~BoardText();

};

