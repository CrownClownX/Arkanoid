#include "Bar.hpp"

Bar::Bar(sf::Texture& texture, const sf::FloatRect& textureData) : texture(texture), velocity(450.0f),
{
	sf::Vector2f size(Const_Var::BAR_DATA.width, Const_Var::BAR_DATA.height);
	sf::Vector2f location(Const_Var::BAR_DATA.left, Const_Var::BAR_DATA.top);

	sprite.setSize(size);
	sprite.setPosition(location);
	sprite.setTexture(&texture);
	sprite.setTextureRect((sf::IntRect)textureData);
}

Bar::~Bar()
{
}

void Bar::update(const float& deltaTime)
{
	int mousePositionX = sf::Mouse::getPosition().x;
	float location = sprite.getPosition().x;

	if (mousePositionX < (location + Const_Var::BAR_DATA.width) && location > 40)
		moveLeft(deltaTime, location);
	else if (mousePositionX > (location + 2 * Const_Var::BAR_DATA.width) && location < (1240 - Const_Var::BAR_DATA.width))
		moveRight(deltaTime, location);

	sprite.setPosition(location, sprite.getPosition().y);
}

void Bar::moveRight(const float& deltaTime, float& location)
{
	location += velocity*deltaTime;
}

void Bar::moveLeft(const float& deltaTime, float& location)
{
	location -= velocity*deltaTime;
}

void Bar::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sprite);
}

