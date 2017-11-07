#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"


class Tile
{
private:
	bool isMovable;
	sf::Sprite sprite;
	Textures::ID id;

public:
	Tile(bool tmpMovable, const sf::Texture& texture);
	~Tile();

	void draw(const sf::Vector2f& location, sf::RenderWindow& window);

};