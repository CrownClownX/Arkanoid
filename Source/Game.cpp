#include "Game.h"

Game::Game(sf::RenderWindow& window) :GameState(window), isRoundStarted(false)
{

}

Game::~Game()
{

}

void Game::draw()
{
	map.draw(window);
}

void Game::eventHandler()
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		else if (event.type == sf::Event::MouseButtonPressed)
			isRoundStarted = true;
	}

	if (event.key.code == sf::Keyboard::Escape)
		window.close();
}

void Game::update(const float& deltaTime)
{
	map.update(deltaTime, isRoundStarted);
}