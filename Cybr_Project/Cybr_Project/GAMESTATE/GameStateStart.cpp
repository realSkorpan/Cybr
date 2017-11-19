#include "GameStateStart.h"
#include "GameStatePlay.h"

void GameStateStart::loadGame() {
	this->game->pushState(new GameStatePlay(this->game));
}

void GameStateStart::moveUp() {
	if (selectedItem - 1 >= 0) {
		text[selectedItem].setFillColor(sf::Color(200, 0, 0));
		selectedItem--;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}

void GameStateStart::moveDown() {
	if (selectedItem + 1 < nrOfItems) {
		text[selectedItem].setFillColor(sf::Color(200, 0, 0));
		selectedItem++;
		text[selectedItem].setFillColor(sf::Color::Red);
	}
}

int GameStateStart::getSelectedItem() {
	return this->selectedItem;
}

void GameStateStart::draw(const float &dt) {
	this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);
	//this->game->window.draw(this->game->background);
	for (int i = 0; i < nrOfItems; i++) {
		this->game->window.draw(text[i]);
	}
}

void GameStateStart::update(const float &dt) {
}

void GameStateStart::handleInput() {
	sf::Event event;
	while (this->game->window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			game->window.close();
			break;

		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				this->moveUp();
				break;

			case sf::Keyboard::Down:
				this->moveDown();
				break;

			case sf::Keyboard::Return:
				switch (getSelectedItem()) {
				case 0:
					this->loadGame();
					break;

				case 1:
					this->game->window.close();
					break;
				}
			}

		default: break;
		}
	}
}

GameStateStart::GameStateStart(Game *game) {
	this->game = game;
	sf::Vector2f pos = sf::Vector2f(this->game->window.getSize());
	std::cout << pos.x << " " << pos.y << std::endl;
	this->view.setSize(pos);
	pos *= 0.5f;
	this->view.setCenter(pos);
	if (!font.loadFromFile("media/arial.ttf")) {
		std::cout << "Error loading font: arial.ttf" << std::endl;
	}
	for (int i = 0; i < nrOfItems; i++) {
		float yPos = 20 * float(i + 1);
		text[i].setFont(font);
		text[i].setFillColor(sf::Color::White);
		text[i].setCharacterSize(24);
		text[i].setPosition(sf::Vector2f(20, yPos));
	}
	text[0].setString("Start");
	text[1].setString("Exit");

	selectedItem = 0;
}