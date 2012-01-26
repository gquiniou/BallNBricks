/*
 * MovingObject.h
 *
 *  Created on: 24 janv. 2012
 *      Author: greg
 */

#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_

#include "game/GameObject.h"

namespace game {

class MovingObject: public virtual GameObject {

public:

	MovingObject(sf::Vector2f vel) : velocity(vel) {}

	virtual ~MovingObject() {}

	sf::Vector2f getVelocity() const;

protected:

	sf::Vector2f velocity;
};

} /* namespace game */
#endif /* MOVINGOBJECT_H_ */
