#include <stack>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "GameState.h"

Game::Game() {

	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;

	screenDimensions.x = 1024;
	screenDimensions.y = 768;
	this->window.create(sf::VideoMode(screenDimensions.x, screenDimensions.y, 32), "Cybr", sf::Style::Default, settings);

	this->window.setFramerateLimit(60);
}

Game::~Game() {
	while (!states.empty()) popState();
}

void Game::pushState(GameState *state) {
	this->states.push(state);
}

void Game::popState() {
	delete this->states.top();
	this->states.pop();
}

void Game::changeState(GameState *state) {
	if (!this->states.empty())
		popState();
	pushState(state);
}

GameState* Game::peekState() {
	if (this->states.empty()) return nullptr;
	return this->states.top();
}

unsigned int Game::getFPS(const sf::Time &time) const {
	return (int)(1.f / time.asSeconds());
}

void Game::gameLoop() {
	sf::Clock clock;

	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();
	}
}