#pragma once

#include <map>
#include <memory>
#include <vector>
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
	std::vector<std::unique_ptr<Brick>> bricks;
	std::unique_ptr<Bar> bar;
	std::unique_ptr<Ball> ball;

	void loadTexture();
	void buildTheMap();
	void buildTheBrick();
	void createBarAndBall();

	void drawTiles(sf::RenderWindow& window);
	void drawBricks(sf::RenderWindow& window);

	bool checkCollision();
public:
	Map();
	~Map();

	void draw(sf::RenderWindow& window);
	void update(const float& deltaTime, const bool& isBallMoving);
};