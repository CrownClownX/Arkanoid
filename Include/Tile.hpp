#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "Collider.hpp"


class Tile : public Collider
{
public:
	Tile(bool tmpMovable, const sf::Texture& texture);
	~Tile();

	void draw(sf::RenderWindow& window);
	void setLocation(const sf::Vector2f& location) { sprite->setPosition(location); }
};