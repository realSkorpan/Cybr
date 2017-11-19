#include "GameStatePlay.h"

void GameStatePlay::draw(const float &dt) {
	this->game->window.setView(this->gameView);
	//this->game->window.clear(sf::Color::Black);
	this->game->tmap->drawTiles(this->game->window);
	this->game->uc.drawUnits(this->game->window);
	drawHighlight(this->game->window, this->game->tmap, this->game->uc.getUnit(0)->getPos());
}

void GameStatePlay::update(const float &dt) {

}

void GameStatePlay::handleInput() {
	sf::Event event;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->game->window.close();
	}
	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			game->window.close();
			break;

		default: break;
		}
	}
}

GameStatePlay::GameStatePlay(Game *game) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	this->gameView.setSize(pos);
	pos *= 0.5f;
	this->gameView.setCenter(pos);

	TilemapGenerator tmg;
	this->game->tmap = tmg.generateBlock(64, 64, 1);
	tmg.createRooms(this->game->tmap);

	pState.playerView(this->game->window);
	this->game->uc.createUnit(0, 0, 0, sf::Vector2f(this->game->window.getView().getCenter().x / 32, this->game->window.getView().getCenter().y / 32));
}