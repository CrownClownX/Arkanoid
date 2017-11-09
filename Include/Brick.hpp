#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "Collider.hpp"

class Brick: public Collider
{
private:
	bool isDestructed; 

public:
	Brick(const sf::Texture& texture);
	~Brick();

	void draw(const sf::Vector2f& location, sf::RenderWindow& window);
	void destruction() { isDestructed = false; }
};

