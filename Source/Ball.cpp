#include "..\Include\Ball.hpp"

Ball::Ball(sf::Texture & texture): Collider(texture, 5), velocity(500), moveVector(0, -500)
{
	location.x = 630.0f;
	location.y = 580.0f;
}

Ball::~Ball()
{
}

void Ball::update(const float& deltaTime, const float& barPosition)
{
		moveOnBar(barPosition);
}

void Ball::update(const float& deltaTime, const sf::Vector2f& newVector, const bool& ifBar)
{
	if (ifBar)
		barVector(newVector);
	else
		changeVector(newVector);

		move(deltaTime);
}

void Ball::draw(sf::RenderWindow & window)
{
	sprite->setPosition(location);
	window.draw(*sprite);
}

void Ball::move(const float& deltaTime)
{
	location.y += deltaTime*moveVector.y;
	location.x += deltaTime*moveVector.x;
}

void Ball::changeVector(const sf::Vector2f& newVector)
{
	moveVector.x *= newVector.x;
	moveVector.y *= newVector.y;
}

void Ball::barVector(const sf::Vector2f& newVector)
{
	moveVector.x = velocity* newVector.x;
	moveVector.y = velocity * newVector.y;
}

void Ball::moveOnBar(const float& barPosition)
{
	location.x = barPosition + 70;
}

