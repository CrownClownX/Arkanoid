#pragma once

#include <map>
#include <memory>
#include <vector>
#include <list>
#include <fstream>
#include <iostream>

#include "Tile.hpp"
#include "Brick.hpp"
#include "TextureHolder.hpp"
#include "Const.h"
#include "Bar.hpp"
#include "Ball.hpp"
#include "CollisionManager.hpp"

class Map : public sf::Drawable
{
private:
	TextureHolder texture; 
	CollisionManager& collision;

	Bar bar;
	Ball ball;
	Brick brick;
	Brick tiles;

	void createBarAndBall();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

public:
	Map();
	~Map();

	void update(const float& deltaTime, const bool& isBallMoving);
};