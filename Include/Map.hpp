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

class Map
{
private:
	TextureHolder texture;
	std::vector<std::unique_ptr<Tile>> tiles;
	std::vector<std::unique_ptr<Brick>> bricks;
	std::unique_ptr<Bar> bar;

	void loadTexture();
	void buildTheMap();
	void buildTheBrick();
	void createBar();

	void drawTiles(sf::RenderWindow& window);
	void drawBricks(sf::RenderWindow& window);

public:
	Map();
	~Map();

	void draw(sf::RenderWindow& window);
	void update();
};