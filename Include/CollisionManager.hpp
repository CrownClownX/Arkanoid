#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Collider.hpp"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
                      
	bool checkCollison(const Collider& ball, const Collider& someObject);
	sf::Vector2f getNewVector(const Collider& ball, const Collider& someObject);
	sf::Vector2f getBarVector(const Collider& ball, const Collider& bar);
};