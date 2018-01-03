#include "..\Include\Collider.hpp"

Collider::Collider(const sf::Texture& texture)
	: isMovable(false), sprite(std::make_unique<sf::RectangleShape>(sf::Vector2f(80, 20)))
{
	sprite->setTexture(&texture);
}

Collider::Collider(const sf::Texture & texture, const bool & tmpIsMovable)
	:isMovable(tmpIsMovable), sprite(std::make_unique<sf::RectangleShape>(sf::Vector2f(40, 40)))
{
	sprite->setTexture(&texture);
}

Collider::Collider(const sf::Texture & texture, const sf::Vector2f totalSize)
	: isMovable(false), sprite(std::make_unique<sf::RectangleShape>(totalSize))
{
	sprite->setTexture(&texture);
}

Collider::Collider(const sf::Texture & texture, const int & circle)
	: isMovable(false), sprite(std::make_unique<sf::CircleShape>(10))
{
	sprite->setTexture(&texture);
}

Collider::~Collider()
{
}
