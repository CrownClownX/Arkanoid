#pragma once

#include <SFML\Graphics.hpp>
#include "Collider.hpp"

class Ball: public Collider
{
private:
	sf::Vector2f location;
	bool collisonChecker;
	float velocity;

	void moveOnBar(const float& barPosition);
	void move(const float& deltaTime);

public:
	Ball(sf::Texture& texture);
	~Ball();

	void update(const float& deltaTime, const float& barPosition);
	void Ball::update(const float& deltaTime, const bool& isColliding);

	void draw(sf::RenderWindow& window);
};