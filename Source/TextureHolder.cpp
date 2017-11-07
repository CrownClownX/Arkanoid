#include "..\Include\TextureHolder.hpp"

#include <iostream>

TextureHolder::TextureHolder()
{
}

TextureHolder::~TextureHolder()
{
}

void TextureHolder::load(Textures::ID id, const std::string & filename)
{
	std::unique_ptr<sf::Texture> tmp = std::make_unique<sf::Texture>();

	if (!tmp->loadFromFile(filename))
		throw std::runtime_error("Texture " + filename);

	textureMap.insert(std::make_pair(id, std::move(tmp)));
}

sf::Texture & TextureHolder::get(Textures::ID id)
{
	auto found = textureMap.find(id);

	return *found->second;
}

const sf::Texture & TextureHolder::get(Textures::ID id) const
{
	auto found = textureMap.find(id);

	return *found->second;
}
