#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include <memory>

#include "Const.h"
#include "Game.h"
#include "Menu.h"

class GameLoop
{
private:
	sf::RenderWindow window;
	std::map<Const_Var::enumState, GameState*> state;
	GameState* currentState;

	void display();
public:
	GameLoop();
	~GameLoop();

	void startGameLoop();
};