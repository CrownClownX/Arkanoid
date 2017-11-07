#pragma once

#include <memory>
#include <map>
#include <SFML\Graphics.hpp>

#include "Const.h"

class TextureHolder
{
private:
	std::map<Textures::ID, std::unique_ptr<sf::Texture>> textureMap;
public:
	TextureHolder();
	~TextureHolder();

	void load(Textures::ID id, const std::string& filename);
	sf::Texture& get(Textures::ID id);
	const sf::Texture& get(Textures::ID id) const;
};