#include "Brick.hpp"

Brick::Brick(const sf::Texture& texture):Collider(texture), isDestructed(false)
{
}

Brick::~Brick()
{
}

void Brick::draw(const sf::Vector2f& location, sf::RenderWindow& window)
{
	if (isDestructed == false)
	{
		sprite.setPosition(location);
		window.draw(sprite);
	}
}
