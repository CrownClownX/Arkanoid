#pragma once

#include <memory>
#include <map>
#include <SFML\Graphics.hpp>

#include "Const.h"
#include <iostream>

class TextureHolder
{
private:
	std::map<Textures::ID, sf::FloatRect> textureMap;
	sf::Texture texture;

	void setCategory();

public:
	TextureHolder(const std::string & filename);
	~TextureHolder();

	bool load(const std::string& filename);
	sf::Texture& get();
	sf::FloatRect getRect(Textures::ID id) const;
};