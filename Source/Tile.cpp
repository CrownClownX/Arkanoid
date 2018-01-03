#include "..\Include\Tile.hpp"

Tile::Tile(bool tmpMovable, const  sf::Texture& texture):Collider(texture, tmpMovable)
{

}

Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow& window)
{
	window.draw(*sprite);
}


