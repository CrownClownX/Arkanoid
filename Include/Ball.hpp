#pragma once

#include <SFML\Graphics.hpp>
#include "CollisionManager.hpp"
#include "Const.h"

class Ball: public sf::Drawable
{
private:
	sf::Texture& texture;
	sf::CircleShape sprite;
	float velocity;
	sf::Vector2f moveVector;

	void moveOnBar(const float& barPosition, float & locationX);
	void move(const float& deltaTime, sf::Vector2f & location);
	void changeVector(const sf::Vector2f& newVector);
	void barVector(const sf::Vector2f& newVector);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Ball(sf::Texture& texture, const sf::FloatRect& textureData);
	~Ball();

	void update(const float& deltaTime, const float& barPosition);
	void update(const float& deltaTime, const bool& ifBall);
	sf::FloatRect getBallRect() const { return sprite.getGlobalBounds(); };
};