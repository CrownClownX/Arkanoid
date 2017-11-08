#pragma once

#include "GameState.h"
#include "Map.hpp"

class Game : public GameState
{
private:
	Map map;
	bool isRondStarted;
public:
	Game(sf::RenderWindow& window);
	~Game();

	void update(const float& deltaTime);
	void eventHandler();
	void draw();
};