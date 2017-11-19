#pragma once
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tile.h"

class Tilemap {
private:
	int width, height;
	std::vector<std::vector<Tile*>> tiles;
public:
	Tilemap(int w, int h);
	~Tilemap();

	void drawTiles(sf::RenderWindow &window, const sf::Vector2i &screenTiles);
	void drawTiles(sf::RenderWindow &window);

	Tile* getTile(int row, int col);
};