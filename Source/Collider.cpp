#include "..\Include\Collider.hpp"

Collider::Collider(const sf::Texture& texture): isMovable(false)
{
	sprite.setTexture(texture);
}

Collider::Collider(const sf::Texture & texture, const bool & tmpIsMovable):isMovable(tmpIsMovable)
{
	sprite.setTexture(texture);
}

Collider::~Collider()
{
}
