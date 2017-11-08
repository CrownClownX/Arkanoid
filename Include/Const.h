#pragma once

#include <SFML\Graphics.hpp>
#include <string>


namespace Const_Var {

	static const sf::VideoMode WINDOW_SIZE(1280, 720);
	static const std::string WINDOW_NAME = "Arkanoid";
	
	static const int TILE_SIZE = 40;
	static const int WIDTH_SIZE = 32;
	static const int HEIGHT_SIZE = 18;

	static const int BRICK_WIDTH = 80;
	static const int BRICK_HEIGHT = 20;

	static const int BAR_WIDTH = 160;
	static const int BAR_HEIGHT = 20;

	static const std::string BACKGROUND_TEXTURE = "../../../Resource/BACKGROUND.png";
	static const std::string WALL_TEXTURE = "../../../Resource/WALL.png";
	static const std::string NORMAL_BRICK = "../../../Resource/Brick0.png";

	static const std::string TILE_MAP = "../../../Resource/Map.txt";
	static const std::string BRICK_MAP = "../../../Resource/BrickMap.txt";

	static const std::string BAR_TEXTURE = "../../../Resource/Bar.png";

	enum enumState {
		MENU, GAME
	};
}

namespace Textures {
	enum ID {
		WALL, BACKGROUND, BRICK, BAR, BALL, NORMAL_BRICK, STRONG_BRICK, MAGIC_BRICK
	};
}

