#include "Tile.h"

const float Tile::TILE_SIZE = 32.f;

Tile::Tile(float cx, float cy, int type, bool obstructed) {
	this->cx = cx;
	this->cy = cy;
	this->type = type;
	this->obstructed = obstructed;

	this->shape = sf::RectangleShape(sf::Vector2f(Tile::TILE_SIZE, Tile::TILE_SIZE));
	this->shape.setPosition(sf::Vector2f((cx - (Tile::TILE_SIZE / 2)), (cy - (Tile::TILE_SIZE / 2))));
	this->shape.setFillColor((type == 0) ? (sf::Color::White) : (sf::Color::Blue));
}

Tile::~Tile() {

}

int Tile::getType() const {
	return this->type;
}

int Tile::getKey() const {
	return this->key;
}

void Tile::setKey(int key) {
	this->key = key;
}

sf::RectangleShape Tile::getShape() const {
	return this->shape;
}

void Tile::setShape(sf::RectangleShape shape) {
	this->shape = shape;
}

void Tile::setColor(sf::Color fill, sf::Color outline) {
	this->shape.setFillColor(fill);
	this->shape.setOutlineColor(outline);
	this->shape.setOutlineThickness(-1);
}