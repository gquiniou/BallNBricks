/*
 * GameObject.h
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "game/gameinfo.h"
#include <SFML/Graphics.hpp>

namespace game {

class GameObject {
public:
	GameObject(gameinfo i) : infos(i) {};

	virtual ~GameObject();

	//virtual void update() = 0;

	virtual sf::Sprite &getDrawable() = 0;

protected:
	gameinfo infos;
};

} /* namespace game */
#endif /* GAMEOBJECT_H_ */
