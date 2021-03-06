/*
 * gamestate.h
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SFML/Graphics.hpp>
#include <cmath>


typedef struct  {
	bool isHorizontal() {
		return fabs(y1 - y2) < 0.1;
	}
	float x1, y1;
	float x2, y2;
} line;


typedef struct sgamestate {
	int mousex;
	bool ballfired;
	sf::FloatRect paddleRect;
	sf::Time frametime;
	line walls[5];
} gamestate;


#endif /* GAMESTATE_H_ */
