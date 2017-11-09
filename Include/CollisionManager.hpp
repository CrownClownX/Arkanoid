#pragma once

#include <SFML\Graphics.hpp>

#include "Collider.hpp"

class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();
                      
	bool checkCollison(const Collider& ball, const Collider& someObject);
};