/*
 * GameObject.h
 *
 *  Created on: 8 janv. 2012
 *      Author: greg
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "game/gamestate.h"
#include <SFML/Graphics.hpp>

namespace game {

class GameObject {

public:

	GameObject() {}

	GameObject(sf::Sprite _sprite) : sprite(_sprite) {}

	virtual ~GameObject() {}

	virtual void update(gamestate &) = 0;

	sf::Sprite &getDrawable() {
		return sprite;
	}

	sf::Vector2f getCenter() {
		sf::FloatRect r = sprite.GetGlobalBounds();
		return sf::Vector2f(r.Left + r.Height /2, r.Top + r.Height / 2);
	}

	sf::FloatRect getRect() const {
		return sprite.GetGlobalBounds();
	}

protected:

	sf::Sprite sprite;
};

} /* namespace game */
#endif /* GAMEOBJECT_H_ */
