#pragma once
#include <stack>
#include <SFML/Graphics.hpp>
#include "../GENERATION/Tilemap.h"
#include "../ENTITY/UnitContainer.h"

class GameState;
class Game {
private:
public:
	Game();
	~Game();

	std::stack<GameState*> states;
	sf::RenderWindow window;
	sf::Vector2i screenDimensions;

	Tilemap *tmap;
	UnitContainer uc;


	void pushState(GameState *state);
	void popState();
	void changeState(GameState *state);
	GameState *peekState();

	unsigned int getFPS(const sf::Time &time) const;
	void gameLoop();
};