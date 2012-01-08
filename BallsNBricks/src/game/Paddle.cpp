/*
 * Paddle.cpp
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#include "game/Paddle.h"
#include <iostream>

namespace game {

void Paddle::init() {
	std::cout << "init";
	if (! tex.LoadFromFile("paddles.png"))
		std::cout << "menfin";
	pad.SetTexture(tex);
	pad.SetTextureRect(sf::IntRect(0, 0, 64, 16));
}

Paddle::~Paddle() {
	// TODO Auto-generated destructor stub
}

void Paddle::update(int mousepos) {
	if (mousepos < 0)
		mousepos = 0;
	if (mousepos + pad.GetGlobalBounds().Width > infos.width)
		mousepos = infos.width - pad.GetGlobalBounds().Width;
	pad.SetPosition(mousepos, infos.height - pad.GetGlobalBounds().Height);
}

sf::Sprite &Paddle::getDrawable() {
	return pad;
}

} /* namespace game */
