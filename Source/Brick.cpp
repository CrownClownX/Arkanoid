#include "Brick.hpp"

Brick::Brick(const sf::Texture& texture, const sf::Vector2f& size, const sf::Vector2i number, const std::string& path)
	: texture(texture), sizeOfTile(size), numberOfTiles(number)
{
	try
	{
		readMap(path);
	}
	catch(std::string file)
	{
		std::cout << "FILE " << file << " NOT FOUND";
	}
}

Brick::~Brick()
{
	if (mapOfBricks != nullptr)
		delete[] mapOfBricks;
}

void Brick::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states = &texture;
	target.draw(vertices, states);
}

void Brick::buildBricks(const int margin, sf::Vector2f startPoint)
{
	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(numberOfTiles.x * numberOfTiles.y * 4);

	for (int i = 0; i < numberOfTiles.x; i++)
	{
		for (int j = 0; j < numberOfTiles.y; j++)
		{
			int tileNumber = mapOfBricks[i + j * numberOfTiles.x];

			sf::Vertex * quad = &vertices[(i + j * numberOfTiles.x) * 4];

			quad[0].position = sf::Vector2f(margin + i * sizeOfTile.x, margin + j * sizeOfTile.y);
			quad[1].position = sf::Vector2f(margin + (i + 1) * sizeOfTile.x, margin + j * sizeOfTile.y);
			quad[2].position = sf::Vector2f(margin + (i + 1) * sizeOfTile.x, margin + (j + 1) * sizeOfTile.y);
			quad[3].position = sf::Vector2f(margin + i * sizeOfTile.x, margin + (j + 1) * sizeOfTile.y);

			quad[0].texCoords = sf::Vector2f(
				(tileNumber*sizeOfTile.x)+startPoint.x, startPoint.y);
			quad[1].texCoords = sf::Vector2f(
				(tileNumber*sizeOfTile.x) + startPoint.x +sizeOfTile.x, startPoint.y);
			quad[2].texCoords = sf::Vector2f(
				(tileNumber*sizeOfTile.x) + startPoint.x + sizeOfTile.x, startPoint.y + sizeOfTile.y);
			quad[3].texCoords = sf::Vector2f(
				(tileNumber*sizeOfTile.x) + startPoint.x, startPoint.y + sizeOfTile.y);
		}
	}
}

void Brick::readMap(const std::string & path)
{
	mapOfBricks = new int[numberOfTiles.x * numberOfTiles.y];

	std::fstream file;
	file.open(path, std::ios::in);

	if (!file.is_open())
		throw path;

	int i = 0;

	while (!file.eof())
		file >> mapOfBricks[i++];

	file.close();
}
