#include "Tilemap.h"
#include <iostream>
Tilemap::Tilemap(int w, int h) {
	this->width = w;
	this->height = h;

	this->tiles.resize(h);
	for (int i = 0; i < h; i++) {
		this->tiles[i].resize(w);
	}

	for (int r = 0; r < this->tiles.size(); r++) {
		for (int c = 0; c < this->tiles[r].size(); c++) {
			//this->tiles[r][c] = new Tile((c * (Tile::TILE_SIZE / 2)), (r * Tile::TILE_SIZE), 0, false);
			this->tiles[r][c] = new Tile(((c * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), ((r * Tile::TILE_SIZE) + (Tile::TILE_SIZE / 2)), 1, false);
		}
	}
}

Tilemap::~Tilemap() {
	for (int r = 0; r < this->tiles.size(); ++r) {
		for (int c = 0; c < this->tiles[r].size(); ++c) {
			delete tiles[r][c];
		}
	}
}

void Tilemap::drawTiles(sf::RenderWindow &window, const sf::Vector2i &screenTiles) {
	sf::Vector2i curView;
	curView.y = window.getView().getCenter().y / 32 - 16;
	curView.x = window.getView().getCenter().x / 32 - 16;
	sf::Vector2i curViewMax;
	curViewMax.y = window.getView().getCenter().y / 32 + 16;
	curViewMax.x = window.getView().getCenter().x / 32 + 16;

	if (curView.y < 0)
		curView.y = 0;
	if (curView.x < 0)
		curView.x = 0;
	if (curViewMax.y > 63)
		curViewMax.y = 63;
	if (curViewMax.x > 63)
		curViewMax.x = 63;

	for (int r = curView.y; r < curViewMax.y; ++r) {
		for (int c = curView.x; c < curViewMax.x; ++c) {
			window.draw(this->tiles[r][c]->getShape());
		}
	}
	std::cout << curView.x << std::endl;
}

void Tilemap::drawTiles(sf::RenderWindow &window) {
	for (int r = 0; r < this->tiles.size(); r++) {
		for (int c = 0; c < this->tiles[r].size(); c++) {
			window.draw(this->tiles[r][c]->getShape());
		}
	}
	//sf::Vector2i curView;
	//curView.x = window.getView().getCenter().x / 32 - 16;
	//curView.y = window.getView().getCenter().y / 32 - 16;
	//sf::Vector2i curViewMax;
	//curViewMax.x = window.getView().getCenter().x / 32 + 18;
	//curViewMax.y = window.getView().getCenter().x / 32 + 18;

	//for (int r = curView.y; r < curViewMax.y; r++) {
	//	for (int c = curView.x; c < curViewMax.x; c++) {
	//		window.draw(this->tiles[r][c]->getRect());
	//	}
	//}
}

Tile* Tilemap::getTile(int row, int col) {
	if (((row >= 0) && (row < this->height)) && ((col >= 0) && (col < this->width)))
		return this->tiles[row][col];
	else return NULL;
}