#include "..\Include\CollisionManager.hpp"

CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::checkCollison(const Collider& ball, const Collider& someObject)
{
	sf::FloatRect ballRect = ball.getSpriteRectangle();
	sf::FloatRect objectRect = someObject.getSpriteRectangle();

	if (objectRect.intersects(ballRect))
		return true;
	else
		false;
}
