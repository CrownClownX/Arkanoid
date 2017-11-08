#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"

class Brick
{
private:
	bool isDestructed; 
	sf::Sprite sprite;

public:
	Brick(const sf::Texture& texture);
	~Brick();

	void draw(const sf::Vector2f& location, sf::RenderWindow& window);
	void destruction() { isDestructed = false; }
};

