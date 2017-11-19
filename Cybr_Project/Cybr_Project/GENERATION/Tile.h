#pragma once
#include <SFML/Graphics/RectangleShape.hpp>

class Tile {
private:
	float cx, cy;
	int type;
	bool obstructed;
	unsigned short int dir;
	int key;
	sf::RectangleShape shape;
public:
	static const float TILE_SIZE;

	Tile(float cx, float cy, int type, bool obstructed);
	~Tile();

	int getType() const;
	int getKey() const;
	void setKey(int key);
	sf::RectangleShape getShape() const;
	void setShape(sf::RectangleShape shape);
	void setColor(sf::Color fill, sf::Color outline);
};