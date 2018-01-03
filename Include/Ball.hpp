#pragma once

#include <SFML\Graphics.hpp>
#include "Collider.hpp"

class Ball: public Collider
{
private:
	sf::Vector2f location;
	float velocity;
	sf::Vector2f moveVector;

	void moveOnBar(const float& barPosition);
	void move(const float& deltaTime);
	void changeVector(const sf::Vector2f& newVector);
	void barVector(const sf::Vector2f& newVector);

public:
	Ball(sf::Texture& texture);
	~Ball();

	void update(const float& deltaTime, const float& barPosition);
	void update(const float& deltaTime, const sf::Vector2f& newVector, const bool& ifBall);

	void draw(sf::RenderWindow& window);
};