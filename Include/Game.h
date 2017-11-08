#pragma once

#include "GameState.h"
#include "Map.hpp"

class Game : public GameState
{
private:
	Map map;
public:
	Game(sf::RenderWindow& window);
	~Game();

	void update();
	void eventHandler();
	void draw();
};