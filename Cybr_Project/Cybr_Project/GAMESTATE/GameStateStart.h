#pragma once
#include <iostream>
#include "GameState.h"

class GameStateStart : public GameState {
private:
	short int nrOfItems = 2;
	short int selectedItem;
	sf::View view;
	sf::Font font;
	sf::Text text[2];
	void loadGame();
	void moveUp();
	void moveDown();
	int getSelectedItem();
public:
	GameStateStart(Game *game);
	virtual void draw(const float &dt);
	virtual void update(const float &dt);
	virtual void handleInput();
};