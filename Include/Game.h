#pragma once

#include "GameState.h"
#include "Map.hpp"

class Game : public GameState
{
private:
	bool isMapSettled;
	Map map;
public:
	Game(sf::RenderWindow& window);
	~Game();

	void update();
	void eventHandler();
	void draw();
};