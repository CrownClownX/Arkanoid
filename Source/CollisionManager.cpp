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

sf::Vector2f CollisionManager::getNewVector(const Collider & ball, const Collider & someObject)
{
	sf::Vector2f newVector(1.0f, 1.0f);
	sf::FloatRect ballRect = ball.getSpriteRectangle();
	sf::FloatRect object = someObject.getSpriteRectangle();
    
	int width = object.width;
	int height = object.height;

	if (object.left > ballRect.left)
		newVector.x = -1.0f;
	else if (ballRect.top > object.top)
		newVector.y = -1.0f;
	else if (object.left < ballRect.left)
		newVector.x = -1.0f;
	else if (ballRect.top < object.top)
		newVector.y = -1.0f;

	return newVector;
}

sf::Vector2f CollisionManager::getBarVector(const Collider & ball, const Collider & bar)
{
	float ballMiddle = ball.getSpriteRectangle().left + (ball.getSpriteRectangle().width/2) ;
	float barMiddle = bar.getSpriteRectangle().left + (bar.getSpriteRectangle().width / 2);
	float barWidth = bar.getSpriteRectangle().width/2;
	
	sf::Vector2f newVector(1, 1);

	if ((ballMiddle < barWidth + 20) && (ballMiddle > barWidth - 20))
		return sf::Vector2f(0, -1);
	else if (ballMiddle > barMiddle)
	{
		newVector.x = abs(barMiddle - ballMiddle)/barWidth;
		newVector.y -= newVector.x;
		newVector.y *= (-1);
		return newVector;
	}
	else if (ballMiddle < barMiddle)
	{
		newVector.x = abs(barMiddle - ballMiddle) / barWidth;
		newVector.y -= newVector.x;
		newVector.y *= (-1);
		newVector.x *= (-1);
		return newVector;
	}

	return sf::Vector2f(1, 1);
}
