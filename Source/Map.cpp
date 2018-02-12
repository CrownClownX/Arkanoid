#include "..\Include\Map.hpp"

Map::Map() : brick(texture.get(), Const_Var::BRICK_SIZE, Const_Var::BRICK_AMOUNT, Const_Var::BRICK_MAP),
	tiles(texture.get(), Const_Var::TILE_SIZE, Const_Var::TILE_AMOUNT, Const_Var::TILE_MAP),
	texture("../../../Resource/tileset.png"), bar(texture.get(), texture.getRect(Textures::BAR)),
	ball(texture.get(), texture.getRect(Textures::BALL)), collision(CollisionManager::get())
{
	createBarAndBall();

	brick.buildBricks(120, sf::Vector2f(80.0f, 20.0f));
	tiles.buildBricks(0, sf::Vector2f(0.0f, 0.0f));
}

Map::~Map()
{
}

void Map::createBarAndBall()
{
	
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(tiles);
	target.draw(brick);
	target.draw(bar);
	target.draw(ball);
}

void Map::update(const float& deltaTime, const bool& isBallMoving)
{
	bar.update(deltaTime);

	if (isBallMoving == false) 
		ball.update(deltaTime, bar.getBarPositionX());
	else
	{
		ball.update(deltaTime, false);
	}	
}

