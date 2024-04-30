#include "Score.h"

Score::Score(sf::Font &Font)
{
	this->scoreValue = 0;

	this->Shape.setSize(sf::Vector2f(70, 40));
	this->Shape.setFillColor(sf::Color::Yellow);
	this->Shape.setPosition(42.5, 50);

	this->Text.setString("SCORE");
	this->Text.setCharacterSize(CHARACTER_SIZE);
	this->Text.setFillColor(sf::Color::White);
	this->Text.setStyle(sf::Text::Bold);
	this->Text.setFont(Font);
	this->Text.setPosition(20, 15);

	this->TextValue.setString(std::to_string(this->scoreValue));
	this->TextValue.setCharacterSize(CHARACTER_SIZE);
	this->TextValue.setFillColor(sf::Color::Black);
	this->TextValue.setStyle(sf::Text::Bold);
	this->TextValue.setFont(Font);
	this->TextValue.setPosition(42.5 + 35, 50);

}

Score::~Score()
{
}

void Score::reset()
{
	this->scoreValue = 0;
	this->TextValue.setString(std::to_string(this->scoreValue));
}

void Score::draw(sf::RenderWindow& window)
{
	window.draw(this->Shape);
	window.draw(this->Text);
	window.draw(this->TextValue);
}

void Score::update()
{
	this->scoreValue++;
	this->TextValue.setString(std::to_string(this->scoreValue));
}
