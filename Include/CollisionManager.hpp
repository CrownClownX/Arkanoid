#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

class CollisionManager
{
private:
	CollisionManager();
	CollisionManager(const CollisionManager& tmp);

public:
	static CollisionManager& get();
    ~CollisionManager();
                      
    bool checkCollison(const sf::FloatRect& ball, const sf::FloatRect& someObject);
    sf::Vector2f getNewVector(const sf::FloatRect& ball, const sf::FloatRect& someObject);
    sf::Vector2f getBarVector(const sf::FloatRect& ball, const sf::FloatRect& bar);
};