#include "Bar.hpp"

Bar::Bar(sf::Texture& texture)
{
	sprite.setTexture(texture);

	location.x = 600.0f;
	location.y = 600.0f;
}

Bar::~Bar()
{
}

void Bar::draw(sf::RenderWindow& window)
{
	sprite.setPosition(location);
	window.draw(sprite);
}

void Bar::update()
{
	int mousePositionX = sf::Mouse::getPosition().x;

	if (mousePositionX < (location.x + Const_Var::BAR_WIDTH))
		moveLeft();
	else if (mousePositionX > (location.x + 2*Const_Var::BAR_WIDTH) )
		moveRight();
}

void Bar::moveRight()
{
	location.x += 2;
}

void Bar::moveLeft()
{
	location.x -= 2;
}
