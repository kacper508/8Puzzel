#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font &Font, std::string TextValue, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	this->shape.setPosition(x,y);
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->text.setFont(Font);
	this->text.setString(TextValue);
	this->text.setFillColor(sf::Color::White);
	this->text.setPosition(x, y);

	this->buttonState = BUTTON_IDLE;
}

Button::~Button()
{
}

void Button::drawButton(sf::RenderWindow& window)
{
	window.draw(this->shape);
	window.draw(this->text);
}

bool Button::update(const sf::Vector2f mousePosition)
{
	this->buttonState = BUTTON_IDLE;

	//Hover
	if (this->shape.getGlobalBounds().contains(mousePosition))
	{
		this->buttonState = BUTTON_HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BUTTON_PRESSED;
		}
	}

	switch (this->buttonState)
	{
	case BUTTON_IDLE:
		this->shape.setFillColor(this->idleColor);
		return false;
		break;
	case BUTTON_HOVER:
		this->shape.setFillColor(this->hoverColor);
		return false;
		break;
	case BUTTON_PRESSED:
		this->shape.setFillColor(this->activeColor);
		return true;
		break;
	}
}

const bool Button::isPressed()
{
	if (this->buttonState == BUTTON_PRESSED)
		return true;
}

