/*
 * Ball.h
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#ifndef BALL_H_
#define BALL_H_

#include "game/MovingObject.h"

namespace game {

class Ball: public game::MovingObject {
public:

	Ball() : MovingObject(sf::Vector2f(-200, -200)), fired(false), lost(false) {
		velocity = sf::Vector2f(-200.0, -200.0);
		init();
	}
	virtual ~Ball();

	void update(gamestate &);

private:
	void init();
	void update(sf::Int32 time, sf::Vector2f &, sf::Vector2f, gamestate &);

	bool fired;
	bool lost;
};

} /* namespace game */
#endif /* BALL_H_ */
