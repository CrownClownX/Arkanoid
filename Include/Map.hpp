#pragma once

#include <map>
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>

#include "Tile.hpp"
#include "TextureHolder.hpp"
#include "Const.h"

class Map
{
private:
	TextureHolder texture;
	std::vector<std::unique_ptr<Tile>> tiles;

	void loadTexture();
	void buildTheMap();

public:
	Map();
	~Map();

	void draw(sf::RenderWindow& window);

};