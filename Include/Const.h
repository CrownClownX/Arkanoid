#pragma once

#include <SFML\Graphics.hpp>
#include <string>


namespace Const_Var {
	
	static const double MS_PER_FRAME = 1000.0 / 60.0;

	/*In all properties consisted of four values
		- first two values - location of the item 
		- last two values - size of the item*/

	//WINDOW PROPERTIES
	static const sf::VideoMode WINDOW_SIZE(1280, 720);
	static const std::string WINDOW_NAME = "Arkanoid";
	
	//TILE PROPERTIES
	static const sf::Vector2f TILE_SIZE(40.0f, 40.0f);
	static const sf::Vector2i TILE_AMOUNT(32, 18);

	//BRICK PROPERTIES
	static const sf::Vector2f BRICK_SIZE(80.0f, 20.0f);
	static const sf::Vector2i BRICK_AMOUNT(13, 8);

	//BAR PROPERTIES
	static const sf::FloatRect BAR_DATA(560, 600, 160, 20);
	
	//BALL PROPERTIES
	static const sf::FloatRect BALL_DATA(630.0f, 580.0f, 10.0f, 10.0f);

	//PATH
	static const std::string TILE_MAP = "../../../Resource/Map.txt";
	static const std::string BRICK_MAP = "../../../Resource/BrickMap.txt";

	enum enumState {
		MENU, GAME
	};
}

namespace Textures {
	enum ID {
		WALL, BACKGROUND, BRICK, BAR, BALL, NORMAL_BRICK, STRONG_BRICK, MAGIC_BRICK
	};
}

