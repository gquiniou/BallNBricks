/*
 * Brick.h
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#ifndef BRICK_H_
#define BRICK_H_

#include "game/Collidable.h"

namespace game {

class Brick: public Collidable  {

public:

	Brick(sf::Sprite _sprite) : GameObject(_sprite) {
		lives = 1;
	}

	void update(gamestate &) {
		if (lives == 0)
			destroyrequest = true;
	}

	virtual ~Brick() {}
};

} /* namespace game */
#endif /* BRICK_H_ */
