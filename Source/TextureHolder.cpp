#include "..\Include\TextureHolder.hpp"

TextureHolder::TextureHolder(const std::string & filename)
{
	setCategory();
	try
	{
		load(filename);
	}
	catch (std::string file)
	{
		std::cout << "FILE " << file << " NOT FOUND";
	}
}

TextureHolder::~TextureHolder()
{
}

void TextureHolder::setCategory()
{
	textureMap[Textures::BACKGROUND] = sf::FloatRect(0, 0, Const_Var::TILE_SIZE.x, Const_Var::TILE_SIZE.y);
	textureMap[Textures::WALL] = sf::FloatRect(40, 0, Const_Var::BRICK_SIZE.x, Const_Var::BRICK_SIZE.y);
	textureMap[Textures::BRICK] = sf::FloatRect(80, 20, Const_Var::BRICK_SIZE.x, Const_Var::BRICK_SIZE.y);
	textureMap[Textures::BAR] = sf::FloatRect(0, 40, Const_Var::BAR_DATA.width, Const_Var::BAR_DATA.height);
	textureMap[Textures::BALL] = sf::FloatRect(80, 0, 20, 20);
}

bool TextureHolder::load(const std::string & filename)
{
	if (!texture.loadFromFile(filename))
		throw std::runtime_error("Texture " + filename);

	return true;
}

sf::Texture & TextureHolder::get()
{
	return texture;
}

sf::FloatRect TextureHolder::getRect(Textures::ID id) const
{
	auto found = textureMap.find(id);

	return found->second;
}
