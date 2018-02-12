#include "..\Include\CollisionManager.hpp"

CollisionManager::CollisionManager()
{
}

CollisionManager & CollisionManager::get()
{
    static CollisionManager singleton;
    return singleton;
}

CollisionManager::~CollisionManager()
{
}

bool CollisionManager::checkCollison(const sf::FloatRect& ball, const sf::FloatRect& someObject)
{
    if (someObject.intersects(ball))
        return true;

    return false;
}

sf::Vector2f CollisionManager::getNewVector(const sf::FloatRect & ball, const sf::FloatRect & someObject)
{
    sf::Vector2f newVector(1.0f, 1.0f);
    
    int width = someObject.width;
    int height = someObject.height;

    if (someObject.left > ball.left)
        newVector.x = -1.0f;
    else if (ball.top > someObject.top)
        newVector.y = -1.0f;
    else if (someObject.left < ball.left)
        newVector.x = -1.0f;
    else if (ball.top < someObject.top)
        newVector.y = -1.0f;

    return newVector;
}

sf::Vector2f CollisionManager::getBarVector(const sf::FloatRect & ball, const sf::FloatRect & bar)
{
    float ballMiddle = ball.left + (ball.width/2) ;
    float barMiddle = bar.left + (bar.width / 2);
    float barWidth = bar.width/2;
    
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
