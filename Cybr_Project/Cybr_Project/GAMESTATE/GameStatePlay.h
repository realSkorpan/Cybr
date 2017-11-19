#pragma once
#include <iostream>
#include "GameState.h"
#include "../PLAYER/PlayerState.h"
#include "../GENERATION/TilemapGenerator.h"
#include "../ENTITY/UnitContainer.h"
#include "../ENTITY/Pathfinder.h"

class GameStatePlay : public GameState {
private:
	sf::View gameView;
	sf::View guiView;
	PlayerState pState;
public:
	GameStatePlay(Game* game);
	virtual void draw(const float &dt);
	virtual void update(const float &dt);
	virtual void handleInput();
};