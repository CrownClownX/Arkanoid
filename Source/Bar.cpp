#include "Bar.hpp"

Bar::Bar(sf::Texture& texture)
{
	sprite.setTexture(texture);

	location.x = 560.0f;
	location.y = 600.0f;

	velocity = 120;
}

Bar::~Bar()
{
}

void Bar::draw(sf::RenderWindow& window)
{
	sprite.setPosition(location);
	window.draw(sprite);
}

void Bar::update(const float& deltaTime)
{
	int mousePositionX = sf::Mouse::getPosition().x;

	if (mousePositionX < (location.x + Const_Var::BAR_WIDTH))
		moveLeft(deltaTime);
	else if (mousePositionX > (location.x + 2*Const_Var::BAR_WIDTH) )
		moveRight(deltaTime);
}

void Bar::moveRight(const float& deltaTime)
{
	location.x += velocity*deltaTime;
}

void Bar::moveLeft(const float& deltaTime)
{
	location.x -= velocity*deltaTime;
}
