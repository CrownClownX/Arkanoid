#include "GameLoop.h"

GameLoop::GameLoop() : currentState(nullptr)
{
	window.create(Const_Var::WINDOW_SIZE, Const_Var::WINDOW_NAME);
	window.setFramerateLimit(60);

	state[Const_Var::enumState::MENU] = new Menu(window);
	state[Const_Var::enumState::GAME] = new Game(window);

	currentState = state[Const_Var::enumState::GAME];
}

GameLoop::~GameLoop()
{
	delete state[Const_Var::enumState::MENU];
	delete state[Const_Var::enumState::GAME];
}

void GameLoop::startGameLoop()
{
	sf::Clock clock;

	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float deltaTime = elapsed.asSeconds();
		currentState->eventHandler();
		currentState->update(deltaTime);
		display();
	}
}

void GameLoop::display()
{
	window.clear();
	currentState->draw();
	window.display();
}

int main()
{
	GameLoop loop;

	loop.startGameLoop();

	return 0;
}