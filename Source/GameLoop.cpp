#include "GameLoop.h"

GameLoop::GameLoop() : currentState(nullptr)
{
	window.create(Const_Var::WINDOW_SIZE, Const_Var::WINDOW_NAME);
	window.setFramerateLimit(60);

	state[Const_Var::enumState::MENU] = new Menu(window);
	state[Const_Var::enumState::GAME] = new Game(window);
}

GameLoop::~GameLoop()
{
	delete state[Const_Var::enumState::MENU];
	delete state[Const_Var::enumState::GAME];
}

void GameLoop::startGameLoop()
{
	currentState = state[Const_Var::enumState::GAME];

	while (window.isOpen())
	{
		currentState->eventHandler();
		update();
		display();
	}
}

void GameLoop::display()
{
	window.clear();
	currentState->draw();
	window.display();
}

void GameLoop::update()
{
}

int main()
{
	GameLoop loop;

	loop.startGameLoop();

	return 0;
}