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

	Ball(gameinfo i) : GameObject(i), fired(false), velocity(-200, -200) {
		init();
	}
	virtual ~Ball();

	void update(gamestate &);

private:
	void init();
	void update(sf::Uint32 time, sf::Vector2f &, sf::Vector2f, gamestate &);

	bool fired;
	sf::Vector2f velocity;
};

} /* namespace game */
#endif /* BALL_H_ */
