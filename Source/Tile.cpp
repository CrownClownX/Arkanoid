#include "..\Include\Tile.hpp"

Tile::Tile(bool tmpMovable, const  sf::Texture& texture):Collider(texture, tmpMovable)
{

}

Tile::~Tile()
{
}

void Tile::draw(const sf::Vector2f & location, sf::RenderWindow& window)
{
	sprite.setPosition(location);
	window.draw(sprite);
}


