#include "Brick.hpp"

Brick::Brick(const sf::Texture& texture):Collider(texture)
{
}

Brick::~Brick()
{
}

void Brick::draw(sf::RenderWindow& window)
{
	window.draw(*sprite);
}
