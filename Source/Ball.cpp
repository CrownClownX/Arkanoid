#include "..\Include\Ball.hpp"

Ball::Ball(sf::Texture & texture): isMoving(false), velocity(240)
{
	sprite.setTexture(texture);
	location.x = 630.0f;
	location.y = 580.0f;
}

Ball::~Ball()
{
}

void Ball::update(const float& deltaTime, const float& barPosition)
{
	if (isMoving == false)
		moveOnBar(barPosition);
	else
		move(deltaTime);
}

void Ball::draw(sf::RenderWindow & window)
{
	sprite.setPosition(location);
	window.draw(sprite);
}

void Ball::move(const float& deltaTime)
{
	location.y -= deltaTime*velocity;
}

void Ball::moveOnBar(const float& barPosition)
{
	location.x = barPosition + 70;
}

