/*
 * Ball.cpp
 *
 *  Created on: 10 janv. 2012
 *      Author: greg
 */

#include "game/Ball.h"
#include "game/ResourceManager.h"
#include "game/GameObjectsManager.h"
#include <iostream>
#include <cmath>
#include <cassert>

namespace game {

static float vlength(const sf::Vector2f);
//sf::Vector2i intersection(line, line);
//float vlength(sf::Vector2f);

template <typename T>
std::ostream& operator<<(std::ostream &os, sf::Vector2<T> &v2) {
  os << " Vector(" << v2.x << ", " << v2.y << ") ";
  return os;
}

void Ball::init() {
	static int nballs = 0;
	std::cout << nballs++ <<std::endl;
	sprite.setTexture(*ResourceManager::getTexture("balls.png"));
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
}

void Ball::update(gamestate &gs) {
	sf::Vector2f newpos(0,0);

	if (gs.ballfired && ! fired) {
		fired = true;
		gs.ballfired = false;
	}

	if (! fired  ) {
		//La balle suit le pad
		newpos.x = gs.paddleRect.left + gs.paddleRect.width/2;
		newpos.y = gs.paddleRect.top - sprite.getGlobalBounds().height;
	} else {
		update(gs.frametime , newpos, sprite.getPosition(), gs);
	}
	sprite.setPosition(newpos.x, newpos.y);

}


void Ball::update(const sf::Uint32 time, sf::Vector2f &newpos, sf::Vector2f origpos, gamestate &gs) {
	float distance;
	sf::Vector2f collisionpoint(0, 0);
	bool ishoriz = false;

	sf::Vector2f empty(0,0);
	sf::Vector2f movement(velocity.x * time / 1000, velocity.y * time / 1000);

	newpos.x = origpos.x + movement.x;
	newpos.y = origpos.y + movement.y;

	line balltrack = {origpos.x , origpos.y, newpos.x, newpos.y};

	GameObjectsManager *gom  = GameObjectsManager::getInstance();
	collisionpoint = gom->getClosestCollision(balltrack, ishoriz, distance);

	if (collisionpoint != empty) {
		if (ishoriz) {
			velocity.y = - velocity.y;
		} else {
			velocity.x = - velocity.x;
		}
		sf::Uint32 remaining = time / (vlength(movement) / distance);
		newpos = collisionpoint;

		newpos.x += 0.1 * (velocity.x >= 0 ? 1 : -1);
		newpos.y += 0.1 * (velocity.y >= 0 ? 1 : -1);

		update(remaining, newpos, newpos, gs);
	}
}

static inline float vlength(const sf::Vector2f v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

} /* namespace game */
