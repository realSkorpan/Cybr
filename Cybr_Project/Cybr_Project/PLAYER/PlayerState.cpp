#include "PlayerState.h"

PlayerState::PlayerState() {

}

void PlayerState::playerView(const sf::RenderWindow &window) {
	screenTiles.x = (int)window.getView().getCenter().x / 32;
	screenTiles.y = (int)window.getView().getCenter().y / 32;
}

sf::Vector2i PlayerState::getScreenTiles() const {
	return this->screenTiles;
}