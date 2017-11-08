#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"

class Bar
{
private:
	sf::Sprite sprite;
	sf::Vector2f location;

	void moveRight();
	void moveLeft();

public:
	Bar(sf::Texture& texture);
	~Bar();

	void draw(sf::RenderWindow& window);
	void update();
};