#pragma once

#include <SFML\Graphics.hpp>


namespace Const_Var {

	static const sf::VideoMode WINDOW_SIZE(1280, 720);
	static const std::string WINDOW_NAME = "Arkanoid";
	
	static const int TILE_SIZE = 40;
	static const int WIDTH_SIZE = 32;
	static const int HEIGHT_SIZE = 18;

	enum enumState {
		MENU, GAME
	};
}

namespace Textures {
	enum ID {
		WALL, BACKGROUND, BRICK, BAR, BALL
	};
}