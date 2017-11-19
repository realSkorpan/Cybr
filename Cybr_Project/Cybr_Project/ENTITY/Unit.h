#pragma once
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Unit {
private:
	int id, faction, level;
	sf::Vector2f pos;
	sf::Vector2f velocity;
	sf::CircleShape shape;
public:
	Unit(int u_id, int faction, int level, sf::Vector2f pos);
	int getId() const;
	sf::Vector2f getPos() const;
	sf::Vector2f getVelocity() const;
	sf::CircleShape& getShape();
	void setShape(sf::CircleShape shape);
	void setColor(sf::Color color);
};