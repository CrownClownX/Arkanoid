#pragma once

#include <SFML\Graphics.hpp>

class Collider
{
protected:
	bool isMovable;
	sf::Sprite sprite;
public:
	Collider(const sf::Texture& texture);
	Collider(const sf::Texture& texture, const bool& tmpIsMovable);
	virtual ~Collider();

	sf::FloatRect getSpriteRectangle() const {return sprite.getGlobalBounds(); }
	bool getIsMovable() const { return isMovable; }
};