#include "UnitContainer.h"

UnitContainer::UnitContainer() {
	unitsCount = 0;
	unitsMax = 32;
	units.resize(unitsMax);
}

UnitContainer::~UnitContainer() {
	for (int i = 0; i < unitsMax; ++i) {
		delete units[i];
	}
}

void UnitContainer::createUnit(int id, int faction, int level, sf::Vector2f pos) {
	units[unitsCount] = new Unit(id, faction, level, pos);
	if (faction == 0) {
		units[unitsCount]->setShape(sf::CircleShape(16));
		units[unitsCount]->getShape().setFillColor(sf::Color::Yellow);
		units[unitsCount]->getShape().setOutlineColor(sf::Color::Black);
		units[unitsCount]->getShape().setOutlineThickness(-4);
	}
	unitsCount++;
}

void UnitContainer::removeUnit(int id) {
	if (units[unitsCount]->getId() == id)
		delete units[id];
}

void UnitContainer::drawUnits(sf::RenderWindow &window) {
	for (int i = 0; i < unitsCount; ++i) {
		window.draw(units[i]->getShape());
	}
}

void UnitContainer::updateUnits(const float &dt) {
	for (int i = 0; i < unitsCount; ++i) {
		units[i]->getShape().move(units[i]->getVelocity() * dt);
	}
}

Unit* UnitContainer::getUnit(int id) const {
	return this->units[id];
}