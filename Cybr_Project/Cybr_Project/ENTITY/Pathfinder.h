#pragma once
#include "../GENERATION/Tilemap.h"

void drawHighlight(sf::RenderWindow &window, Tilemap* tmap, sf::Vector2f pos);
void createPath(sf::Vector2i dest);