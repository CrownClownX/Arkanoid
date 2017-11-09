#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "Collider.hpp"


class Tile : public Collider
{
public:
	Tile(bool tmpMovable, const sf::Texture& texture);
	~Tile();

	void draw(const sf::Vector2f& location, sf::RenderWindow& window);
};