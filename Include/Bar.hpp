#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "CollisionManager.hpp"

class Bar: public sf::Drawable
{
private:
	sf::Texture& texture;
	sf::RectangleShape sprite;
	float velocity;

	void moveRight(const float& deltaTime, float& location);
	void moveLeft(const float& deltaTime, float& location);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Bar(sf::Texture& texture, const sf::FloatRect& textureData);
	~Bar();

	void update(const float& deltaTime);
	float getBarPositionX() { return sprite.getPosition().x; };
	sf::FloatRect getBarRect() const { return sprite.getGlobalBounds(); };

};