#pragma once

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

enum BUTTON_STATES { BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_PRESSED };

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape shape;
	sf::Text text;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	Button(float x, float y, float width, float height,
		sf::Font &Font,std::string TextValue,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();

	const bool isPressed();

	void drawButton(sf::RenderWindow& window);
	bool update(const sf::Vector2f mousePosition);
};

