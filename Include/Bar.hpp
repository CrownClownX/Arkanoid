#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"

class Bar
{
private:
	sf::Sprite sprite;
	sf::Vector2f location;
	float velocity;

	void moveRight(const float& deltaTime);
	void moveLeft(const float& deltaTime);

public:
	Bar(sf::Texture& texture);
	~Bar();

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime);

	float getBarPositionX() { return sprite.getPosition().x; };
};