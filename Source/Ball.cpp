#include "..\Include\Ball.hpp"

Ball::Ball(sf::Texture & texture, const sf::FloatRect& textureData): texture(texture), 
	velocity(500), moveVector(0, -500)
{
	sf::Vector2f size(Const_Var::BALL_DATA.width, Const_Var::BALL_DATA.height);
	sf::Vector2f location(Const_Var::BALL_DATA.left, Const_Var::BALL_DATA.top);

	sprite.setRadius(size.x);
	sprite.setPosition(location);
	sprite.setTexture(&texture);
	sprite.setTextureRect((sf::IntRect)textureData);
}

Ball::~Ball()
{
}

void Ball::update(const float& deltaTime, const float& barPosition)
{
	float locationX(sprite.getPosition().x);
	moveOnBar(barPosition, locationX);
	sprite.setPosition(locationX, sprite.getPosition().y);
}

void Ball::update(const float& deltaTime, const bool& ifBar)
{
	sf::Vector2f newVector(1, 1);

	if (ifBar)
		barVector(newVector);
	else
		changeVector(newVector);

	sf::Vector2f location(sprite.getPosition());

	move(deltaTime, location);
	sprite.setPosition(location);
}

void Ball::move(const float& deltaTime, sf::Vector2f & location)
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

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite);
}

void Ball::moveOnBar(const float& barPosition, float & locationX)
{
	locationX = barPosition + 70;
}

