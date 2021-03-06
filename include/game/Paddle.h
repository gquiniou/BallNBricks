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
	Paddle() {
		init();
	};

	virtual ~Paddle();

	void update(gamestate &);

private:
	void init();
};

} /* namespace game */
#endif /* PADDLE_H_ */
