#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Unit.h"
#include "PlayerUnit.h"
#include "NpcUnit.h"

class UnitContainer {
private:
	std::vector<Unit*> units;
	int unitsCount, unitsMax;
public:
	UnitContainer();
	~UnitContainer();
	void createUnit(int id, int faction, int level, sf::Vector2f pos);
	void removeUnit(int id);
	void drawUnits(sf::RenderWindow &window);
	void updateUnits(const float &dt);
	
	Unit* getUnit(int id) const;
};