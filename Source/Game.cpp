#include "Game.h"

Game::Game(sf::RenderWindow& window) :GameState(window)
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
	}

	if (event.key.code == sf::Keyboard::Escape)
		window.close();
}

void Game::update()
{
	map.update();
}