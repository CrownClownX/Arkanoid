#include "Menu.h"

Menu::Menu(sf::RenderWindow& tmpWindow):GameState(tmpWindow)
{

}

Menu::~Menu()
{

}

void Menu::draw()
{

}

void Menu::eventHandler()
{
	if (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

	if (event.key.code == sf::Keyboard::Escape)
		window.close();
}

void Menu::update(const float& deltaTime)
{

}