/*
 * Paddle.h
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#ifndef PADDLE_H_
#define PADDLE_H_

#include "GameObject.h"

namespace game {

class Paddle: public GameObject {
public:
	Paddle(gameinfo i) : GameObject(i) {
		init();
	};

	virtual ~Paddle();

	void update(int);

	sf::Sprite &getDrawable();

private:
	void init();
	sf::Sprite pad;
	sf::Texture tex;
};

} /* namespace game */
#endif /* PADDLE_H_ */
