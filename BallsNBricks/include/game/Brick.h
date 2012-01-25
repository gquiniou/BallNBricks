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

class Brick: public GameObject  {
public:
//	Brick(gameinfo i) {}
	Brick(sf::Sprite _sprite) : GameObject(_sprite) {
	};
	void update(gamestate &) { };
	virtual ~Brick();
};

} /* namespace game */
#endif /* BRICK_H_ */
