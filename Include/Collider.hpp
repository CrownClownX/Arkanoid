#pragma once

#include <SFML\Graphics.hpp>
#include <memory>

class Collider
{
protected:
	bool isMovable;
	std::unique_ptr<sf::Shape> sprite;

public:
	Collider(const sf::Texture& texture);
	Collider(const sf::Texture& texture, const bool& tmpIsMovable);
	Collider(const sf::Texture& texture, const sf::Vector2f totalSize);
	Collider(const sf::Texture& texture, const int& circle);
	virtual ~Collider();

	sf::FloatRect getSpriteRectangle() const {return sprite->getGlobalBounds(); }
	bool getIsMovable() const { return isMovable; }
};