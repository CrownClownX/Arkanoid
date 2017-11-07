#include "..\Include\Map.hpp"

Map::Map()
{
	loadTexture();
	buildTheMap();
}

Map::~Map()
{
}

void Map::loadTexture()
{
	texture.load(Textures::WALL, "../../../Resource/WALL.png");
	texture.load(Textures::BACKGROUND, "../../../Resource/BACKGROUND.png");
}

void Map::buildTheMap()
{
	std::fstream file; 
	file.open("../../../Resource/Map.txt", std::ios::in);
	
	while (!file.eof())
	{
		std::unique_ptr<Tile> tmpTile = nullptr;
		int echo;
		file >> echo;

		if (echo == 0)
			tmpTile = std::make_unique<Tile>(true, texture.get(Textures::BACKGROUND));
		else if(echo == 1)
			tmpTile = std::make_unique<Tile>(true, texture.get(Textures::WALL));

		tiles.push_back(std::move(tmpTile));
	}
	
	file.close();
}

void Map::draw(sf::RenderWindow& window)
{
	sf::Vector2f location(0.0f, 0.0f);

	int countingX = 1;
	int countingY = 1;

	for (auto&& iterator : tiles)
	{
		iterator->draw(location, window);
		location.x = countingX * 40;

		if (countingX == 32)
		{
			location.x = 0;
			location.y = countingY * 40;

			countingX = 0;
			countingY++;
		}

		countingX++;
	}
}