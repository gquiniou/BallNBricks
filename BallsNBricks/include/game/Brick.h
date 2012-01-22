/*
 * Brick.h
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#ifndef BRICK_H_
#define BRICK_H_

#include "game/GameObject.h"


namespace game {

class Brick: public game::GameObject {
public:
	Brick(gameinfo i) : GameObject(i) {}
	Brick(gameinfo i, sf::Sprite _sprite) : GameObject(i) {
		this->sprite = _sprite;
	};
	void update(gamestate &) { };
	virtual ~Brick();
};

} /* namespace game */
#endif /* BRICK_H_ */
