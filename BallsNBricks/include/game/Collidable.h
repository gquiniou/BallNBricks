/*
 * Collidable.h
 *
 *  Created on: 25 janv. 2012
 *      Author: greg
 */

#ifndef COLLIDABLE_H_
#define COLLIDABLE_H_

#include "game/GameObject.h"

namespace game {

class Collidable : public virtual GameObject {

public:
	Collidable() {}

	Collidable(sf::Sprite _sprite) : GameObject(_sprite) {}

	int getCollisionRadius() {
		//sf::FloatRect fr = sprite.GetGlobalBounds();
		return 0;
	}

	bool mustCheckCollisions() const {
		return checkcollisions;
	}

private:

	bool checkcollisions;
};

} /* namespace game */
#endif /* COLLIDABLE_H_ */
