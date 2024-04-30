#pragma once
#include <SFML/System/Time.hpp>

class State
{
public:
	State();
	virtual ~State();
	virtual void init() = 0;
	virtual void proccesInput() = 0;
	virtual void update(sf::Time deltaTime) = 0;

	virtual void draw();
	virtual void start();

};
