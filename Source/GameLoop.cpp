#include "GameLoop.h"

GameLoop::GameLoop() : currentState(Const_Var::GAME)
{
	window.create(Const_Var::WINDOW_SIZE, Const_Var::WINDOW_NAME);
	window.setFramerateLimit(60);

	state[Const_Var::enumState::MENU] = std::make_unique<Menu>(window);
	state[Const_Var::enumState::GAME] = std::make_unique<Game>(window);

}

GameLoop::~GameLoop()
{
}

void GameLoop::startGameLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();

		state[currentState]->eventHandler();
		state[currentState]->update(deltaTime);
		display();
	}
}

void GameLoop::display()
{
	window.clear();
	state[currentState]->draw();
	window.display();
}

int main()
{
	GameLoop loop;

	loop.startGameLoop();

	return 0;
}