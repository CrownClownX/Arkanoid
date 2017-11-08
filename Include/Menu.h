#pragma once

#include "GameState.h"

class Menu : public GameState
{
public:
	Menu(sf::RenderWindow& tmpWindow);
	~Menu();

	void update(const float& deltaTime);
	void eventHandler();
	void draw();
};