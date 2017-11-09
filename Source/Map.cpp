#include "..\Include\Map.hpp"

Map::Map() 
{
	loadTexture();
	buildTheMap();
	buildTheBrick();
	createBarAndBall();
}

Map::~Map()
{
}

void Map::loadTexture()
{
	texture.load(Textures::WALL, Const_Var::WALL_TEXTURE);
	texture.load(Textures::BACKGROUND, Const_Var::BACKGROUND_TEXTURE);
	texture.load(Textures::NORMAL_BRICK, Const_Var::NORMAL_BRICK);
	texture.load(Textures::BAR, Const_Var::BAR_TEXTURE);
	texture.load(Textures::BALL, Const_Var::BALL_TEXTURE);
}

void Map::buildTheMap()
{
	std::fstream file; 
	file.open(Const_Var::TILE_MAP, std::ios::in);
	
	while (!file.eof())
	{
		std::unique_ptr<Tile> tmpTile = nullptr;
		int echo;
		file >> echo;

		if (echo == 0)
			tmpTile = std::make_unique<Tile>(true, texture.get(Textures::BACKGROUND));
		else if(echo == 1)
			tmpTile = std::make_unique<Tile>(false, texture.get(Textures::WALL));

		tiles.push_back(std::move(tmpTile));
	}
	
	file.close();
}

void Map::buildTheBrick()
{
	std::fstream file;
	file.open(Const_Var::BRICK_MAP, std::ios::in);

	while (!file.eof())
	{
		std::unique_ptr<Brick> tmpBrick = nullptr;
		int echo;
		file >> echo;

		if (echo == 0)
			tmpBrick = std::make_unique<Brick>(texture.get(Textures::NORMAL_BRICK));
		else if (echo == 1)
			tmpBrick = std::make_unique<Brick>(texture.get(Textures::STRONG_BRICK));

		bricks.push_back(std::move(tmpBrick));
	}

	file.close();
}

void Map::createBarAndBall()
{
	bar = std::make_unique<Bar>(texture.get(Textures::BAR));
	ball = std::make_unique<Ball>(texture.get(Textures::BALL));
}

void Map::draw(sf::RenderWindow& window)
{
	drawTiles(window);
	drawBricks(window);
	bar->draw(window);
	ball->draw(window);
}

void Map::drawTiles(sf::RenderWindow & window)
{
	sf::Vector2f location(0.0f, 0.0f);

	int countingX = 1;
	int countingY = 1;

	for (auto&& iterator : tiles)
	{
		iterator->draw(location, window);
		location.x = countingX * 40.0f;

		if (countingX == 32)
		{
			location.x = 0;
			location.y = countingY * 40.0f;

			countingX = 0;
			countingY++;
		}

		countingX++;
	}
}

void Map::drawBricks(sf::RenderWindow & window)
{
	sf::Vector2f location(120.0f, 120.0f);

	int countingX = 1;
	int countingY = 1;

	for (auto&& iterator : bricks)
	{
		iterator->draw(location, window);
		location.x = countingX * 80.0f + 120.0f;

		if (countingX == 13)
		{
			location.x = 120.0f;
			location.y = countingY * 20.0f + 120.0f;

			countingX = 0;
			countingY++;
		}
		countingX++;
	}
}

bool Map::checkCollision()
{
	bool isColliding;
	for (auto && iterator : tiles)
	{
		if(!iterator->getIsMovable())
			isColliding = collision.checkCollison(*ball, *iterator);

		if (isColliding)
			return true;
	}

	for (auto&& iterator : bricks)
	{
		isColliding = collision.checkCollison(*ball, *iterator);

		if (isColliding)
			return true;
	}

	return false;
}

void Map::update(const float& deltaTime, const bool& isBallMoving)
{
	bar->update(deltaTime);
	if (isBallMoving == false)
		ball->update(deltaTime, bar->getBarPositionX());
	else
		ball->update(deltaTime, checkCollision());
}

