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

class Map
{
private:
	CollisionManager collision;
	TextureHolder texture;
	std::vector<std::unique_ptr<Tile>> tiles;
	std::list<std::unique_ptr<Brick>> bricks;
	std::unique_ptr<Bar> bar;
	std::unique_ptr<Ball> ball;

	void loadTexture();
	void buildTheMap();
	void buildTheBrick();
	void createBarAndBall();

	void drawTiles();
	void drawBricks();

	sf::Vector2f checkCollision();
public:
	Map();
	~Map();

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime, const bool& isBallMoving);
};