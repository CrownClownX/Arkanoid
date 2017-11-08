#pragma once

#include <SFML\Graphics.hpp>

class Ball
{
private:
	sf::Sprite sprite;
	sf::Vector2f location;
	bool isMoving;
	float velocity;

	void moveOnBar(const float& barPosition);
	void move(const float& deltaTime);

public:
	Ball(sf::Texture& texture);
	~Ball();

	void update(const float& deltaTime, const float& barPosition);
	void draw(sf::RenderWindow& window);

	void setIsMovingOn(const bool& isBallMoving) { isMoving = isBallMoving; }
};