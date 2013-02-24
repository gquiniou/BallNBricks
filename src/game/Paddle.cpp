/*
 * Paddle.cpp
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#include "game/Paddle.h"
#include "game/ResourceManager.h"
#include <iostream>

namespace game {

void Paddle::init() {
	std::cout << "init";
	sprite.SetTexture(*ResourceManager::getTexture("paddles.png"));
	sprite.SetTextureRect(sf::IntRect(0, 0, 64, 16));
}

Paddle::~Paddle() {
	// TODO Auto-generated destructor stub
}

void Paddle::update(gamestate &gs) {
	int x = gs.mousex;
	int y = 600 - sprite.GetGlobalBounds().Height;
	if (x < 0)
		x = 0;
	if (x + sprite.GetGlobalBounds().Width > 800)
		x = 800 - sprite.GetGlobalBounds().Width;
	sprite.SetPosition(x, y);
}

} /* namespace game */
