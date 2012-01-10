/*
 * Ball.cpp
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#include "game/Ball.h"
#include <iostream>

namespace game {


Ball::~Ball() {
	// TODO Auto-generated destructor stub
}

void Ball::init() {

}

void Ball::update(gamestate &gs) {
	std::cout << gs.mousex << std::endl;
}

} /* namespace game */
