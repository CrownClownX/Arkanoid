#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "Collider.hpp"

class Brick: public Collider
{

public:
	Brick(const sf::Texture& texture);
	~Brick();

	void draw(sf::RenderWindow& window);
	void setLocation(const sf::Vector2f& location) { sprite->setPosition(location); }
};

