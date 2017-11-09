#include "..\Include\Ball.hpp"

Ball::Ball(sf::Texture & texture): Collider(texture), velocity(240), collisonChecker(false)
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

void Ball::update(const float& deltaTime, const bool& isColliding)
{
	if(collisonChecker)
	{ }
	else if (isColliding)
		collisonChecker = true;
	else if (!isColliding)
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

