#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class PlayerState
{
private:
	sf::Vector2i screenTiles;
public:
	PlayerState();
	void playerView(const sf::RenderWindow& window);

	sf::Vector2i getScreenTiles() const;
};