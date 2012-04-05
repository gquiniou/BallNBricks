/*
 * Collidable.h
 *
 *  Created on: 25 janv. 2012
 *      Author: greg
 */

#ifndef COLLIDABLE_H_
#define COLLIDABLE_H_

#include "game/GameObject.h"
#include <algorithm>

namespace game {

class Collidable : public virtual GameObject {

public:
	Collidable() {}

	Collidable(sf::Sprite _sprite) : GameObject(_sprite) {}

	int getCollisionRadius() {
		sf::FloatRect r = sprite.GetGlobalBounds();
		return std::max(r.Width, r.Height) / 2;
	}

	void hit() {
		lives--;
		washit = true;
	}
	bool isalive() {
		return lives > 0;
	}
protected:
	int lives;
	bool washit;
private:
};

} /* namespace game */
#endif /* COLLIDABLE_H_ */
