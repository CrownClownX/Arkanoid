#pragma once

#include <SFML\Graphics.hpp>

class GameState
{
protected:
	sf::Event event;
	sf::RenderWindow& window;
public:
	GameState(sf::RenderWindow& tmpWindow);
	virtual ~GameState();
	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void eventHandler() = 0;
};