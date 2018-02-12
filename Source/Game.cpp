#include "Game.h"

Game::Game(sf::RenderWindow& window) :GameState(window), isRoundStarted(false)
{

}

Game::~Game()
{

}

void Game::draw()
{
	window.draw(map);
}

void Game::eventHandler()
{
	if (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed :
		{
			window.close();
			break;
		}
		case sf::Event::MouseButtonPressed :
		{
			isRoundStarted = true;
			break;
		}
		}
	}

	if (event.key.code == sf::Keyboard::Escape)
		window.close();
}

void Game::update(const float& deltaTime)
{
	map.update(deltaTime, isRoundStarted);
}