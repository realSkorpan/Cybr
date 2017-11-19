#include "Unit.h"

Unit::Unit(int id, int faction, int level, sf::Vector2f pos) {
	this->id = id;
	this->faction = faction;
	this->level = level;
	this->pos = pos;
}

int Unit::getId() const {
	return this->id;
}

sf::Vector2f Unit::getPos() const {
	return this->pos;
}

sf::Vector2f Unit::getVelocity() const {
	return this->velocity;
}

sf::CircleShape& Unit::getShape() {
	return this->shape;
}

void Unit::setShape(sf::CircleShape shape) {
	this->shape = shape;
}

void Unit::setColor(sf::Color color) {
	this->shape.setFillColor(color);
}