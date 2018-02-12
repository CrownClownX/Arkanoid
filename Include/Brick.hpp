#pragma once

#include <SFML\Graphics.hpp>

#include "Const.h"
#include "Collider.hpp"
#include <fstream>
#include <string>
#include <iostream>

class Brick: public sf::Drawable
{
private:
	sf::VertexArray vertices;
	const sf::Texture& texture;

	sf::Vector2f sizeOfTile;
	sf::Vector2i numberOfTiles;
	int* mapOfBricks;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void readMap(const std::string & path);

public:
	Brick(const sf::Texture& texture, const sf::Vector2f& size, const sf::Vector2i number, const std::string& path);
	~Brick();

	void buildBricks(const int margin, sf::Vector2f startPoint);
	
};

