#include "Pathfinder.h"
#define _USE_MATH_DEFINES

#include <math.h>
#include <SFML/Window/Mouse.hpp>
void drawHighlight(sf::RenderWindow &window, Tilemap *tmap, sf::Vector2f location) {
	std::vector<sf::Vector2f> next;
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	sf::Vector2f destination = window.mapPixelToCoords(mousePosition);
	destination.y += 16;
	destination.x += 16;
	location.y += 16;
	location.x += 16;
	sf::Vector2i destination_i;
	sf::Vector2i location_i;
	destination_i.y = (int)floorf(destination.y / 32);
	destination_i.x = (int)floorf(destination.x / 32);
	location_i.y = (int)floorf(location.y / 32);
	location_i.x = (int)floorf(location.x / 32);

	if (destination_i.x >= 0 && destination_i.y >= 0 &&
		destination_i.x <= 63 && destination_i.y <= 63) {
		
		sf::RectangleShape rshape = sf::RectangleShape(sf::Vector2f(32, 32));
		rshape.setOrigin(16, 16);
		rshape.setPosition((float)destination_i.x * 32, (float)destination_i.y * 32);
		if (tmap->getTile(destination_i.y, destination_i.x)->getType() == 0)
			rshape.setFillColor(sf::Color(255, 0, 0, 50));
		else if (tmap->getTile(destination_i.y, destination_i.x)->getType() == 1)
			rshape.setFillColor(sf::Color(255, 255, 0, 50));
		else
			rshape.setFillColor(sf::Color(0, 255, 0, 50));
		window.draw(rshape);
	}

	float angle = atan2(destination.y - location.y, destination.x - location.x) * 180 / (float)M_PI;
	//int octant = calculateOctant(angle); !!!

	bool swap = abs(destination_i.y - location_i.y) > abs(destination_i.x - location_i.x);
	if (swap) {
		std::swap(location_i.x, location_i.y);
		std::swap(destination_i.x, destination_i.y);
	}
	if (location_i.x > destination_i.x) {
		std::swap(location_i.x, destination_i.x);
		std::swap(location_i.y, destination_i.y);
	}

	//switchToOctant_onInput(octant, locationi.x, destinationi.x);
	//switchToOctant_onOutput(octant, locationi.x, locationi.y);

	int nrshapes = 0;
	for (int x = location_i.x; x < destination_i.x + 1; ++x)
		++nrshapes;
	next.resize(nrshapes);
	sf::RectangleShape* shapes = new sf::RectangleShape[nrshapes];
	for (int i = 0; i < nrshapes; ++i) {
		shapes[i].setSize(sf::Vector2f(32, 32));
		shapes[i].setOrigin(16, 16);
		shapes[i].setFillColor(sf::Color(0, 0, 255, 100));
	}

	int dx = destination_i.x - location_i.x;
	int dy = (int)std::floor(abs(destination_i.y - location_i.y));
	int error = (int)std::floor(dx / 2); // dx * 0.5 for optimization?
	int y = location_i.y;
	int ystep = (location_i.y < destination_i.y) ? 1 : -1;
	if (swap) {
		for (int x = 0; x < dx + 1; ++x) {
			int nx = x + location_i.x;
			shapes[x].setPosition((float)y * 32, (float)nx * 32);
			next[x] = sf::Vector2f((float)y * 32, (float)nx * 32);
			error -= dy;
			if (error < 0) {
				y = y + ystep;
				error = error + dx;
			}
		}
	}
	else {
		for (int x = 0; x < dx + 1; ++x) {
			int nx = x + location_i.x;
			shapes[x].setPosition((float)nx * 32, (float)y * 32);
			next[x] = sf::Vector2f((float)nx * 32, (float)y * 32);
			error -= dy;
			if (error < 0) {
				y = y + ystep;
				error = error + dx;
			}
		}
	}
	for (int i = 0; i < nrshapes; ++i) {
		window.draw(shapes[i]);
	}
	delete[] shapes;

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(location.x - 16, location.y - 16), sf::Color::Red),
		sf::Vertex(sf::Vector2f(destination.x - 16, destination.y - 16), sf::Color::Red)
	};

	window.draw(line, 4, sf::Lines);
}