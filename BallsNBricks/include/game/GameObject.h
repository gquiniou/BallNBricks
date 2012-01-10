/*
 * GameObject.h
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "game/gamestate.h"
#include "game/gameinfo.h"
#include <SFML/Graphics.hpp>

namespace game {

class GameObject {
public:
	GameObject(gameinfo i) : infos(i) {};

	virtual ~GameObject();

	virtual void update(gamestate &) = 0;

	sf::Sprite &getDrawable()  {
		return sprite;
	}
	sf::FloatRect getRect() const {
		return sprite.GetGlobalBounds();
	}

protected:
	gameinfo infos;
	sf::Sprite sprite;
	sf::Texture texture;
};

} /* namespace game */
#endif /* GAMEOBJECT_H_ */
