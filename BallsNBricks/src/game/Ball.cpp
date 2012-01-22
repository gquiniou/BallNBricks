/*
 * Ball.cpp
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#include "game/Ball.h"
#include <iostream>
#include <cmath>
#include <cassert>

namespace game {

sf::Vector2i intersection(line, line);
float vlength(sf::Vector2f);

template <typename T>
std::ostream& operator<<(std::ostream &os, sf::Vector2<T> &v2) {
  os << " Vector(" << v2.x << ", " << v2.y << ") ";
  return os;
}


Ball::~Ball() {
	// TODO Auto-generated destructor stub
}

void Ball::init() {
	static int nballs = 0;
	std::cout << nballs++ <<std::endl;
	if (! texture.LoadFromFile("balls.png"))
		std::cout << "menfin";
	sprite.SetTexture(texture);
	sprite.SetTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Ball::update(gamestate &gs) {
	sf::Vector2f newpos(0,0);

	if (gs.ballfired && ! fired) {
		fired = true;
		gs.ballfired = false;
	}

	if (! fired  ) {
		//La balle suit le pad
		newpos.x = gs.paddleRect.Left + gs.paddleRect.Width/2;
		newpos.y = gs.paddleRect.Top - sprite.GetGlobalBounds().Height;
	} else {
		update(gs.frametime , newpos, sprite.GetPosition(), gs);
	}
	sprite.SetPosition(newpos.x, newpos.y);

}


void Ball::update(const sf::Uint32 time, sf::Vector2f &newpos, sf::Vector2f origpos, gamestate &gs) {
	float closest = 100000;
	sf::Vector2f collisionpoint(0, 0);
	bool ishoriz = false;

	sf::Vector2f empty(0,0);
	sf::Vector2f movement(velocity.x * time / 1000, velocity.y * time / 1000);

	newpos.x = origpos.x + movement.x;
	newpos.y = origpos.y + movement.y;

	line balltrack = {origpos.x , origpos.y, newpos.x, newpos.y};

	//Checking collisions against Walls and Paddle
	for (int i = 0; i < 5 ; i++) {
		sf::Vector2f point(intersection(balltrack, gs.walls[i]));
		if (point != empty) {
			float length = vlength( point - origpos);
			if (length < closest) {
				closest = length;
				collisionpoint = point;
				ishoriz = gs.walls[i].isHorizontal();
			}
		}
	}
	if (collisionpoint != empty) {
		if (ishoriz) {
			velocity.y = - velocity.y;
		} else {
			velocity.x = - velocity.x;
		}
		sf::Uint32 remaining = time / (vlength(movement) / closest);
		newpos = collisionpoint;

		assert(newpos.x >= 0 && newpos.y >= 0);

		if (newpos.x < 0 || newpos.y > 800 || newpos.y < 0 || newpos.y > 600)
			std::cout << "problem";

		newpos.x += 0.1 * (velocity.x >= 0 ? 1 : -1);
		newpos.y += 0.1 * (velocity.y >= 0 ? 1 : -1);

		update(remaining, newpos, newpos, gs);
	}
}

inline float vlength(const sf::Vector2f v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2i intersection(const line l1, const line l2) {
	sf::Vector2i result(0, 0);

	int denom = ((l2.y2-l2.y1) * (l1.x2-l1.x1)) - ((l2.x2-l2.x1) * (l1.y2-l1.y1));
	if (denom != 0) {
		float ua = (((l2.x2-l2.x1) * (l1.y1-l2.y1)) - ((l2.y2-l2.y1) * (l1.x1-l2.x1))) / denom;
		if ((ua >= 0) && (ua <= 1)) {
			float ub = (((l1.x2-l1.x1) * (l1.y1-l2.y1)) - ((l1.y2-l1.y1) * (l1.x1-l2.x1))) / denom;
			if ((ub >= 0) && (ub <= 1)) {
				result.x = l1.x1 + (ua * (l1.x2-l1.x1));
				result.y = l1.y1 + (ua * (l1.y2-l1.y1));
			}
		}
	}
	return result;
}

} /* namespace game */
