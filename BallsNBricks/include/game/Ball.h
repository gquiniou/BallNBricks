/*
 * Ball.h
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#ifndef BALL_H_
#define BALL_H_

#include "game/GameObject.h"

namespace game {

class Ball: public game::GameObject {
public:

	Ball(gameinfo i) : GameObject(i) {
		init();
	}
	virtual ~Ball();

	void update(gamestate &);

private:
	void init();
};

} /* namespace game */
#endif /* BALL_H_ */
