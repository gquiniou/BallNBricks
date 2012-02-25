/*
 * gamestate.h
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include <SFML/Graphics.hpp>



struct line  {
	line(float _x1, float _y1, float _x2, float _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2)  {}
	bool ishorizontal() {
		return fabs(y1 - y2) < 0.1;
	}
	float x1, y1;
	float x2, y2;
};


typedef struct sgamestate {
	int mousex;
	bool ballfired;
	sf::FloatRect paddleRect;
	sf::Uint32 frametime;
	//line walls[5];
} gamestate;


#endif /* GAMESTATE_H_ */
