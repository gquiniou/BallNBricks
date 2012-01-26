/*
 * Critter.h
 *
 *  Created on: 26 janv. 2012
 *      Author: greg
 */

#ifndef CRITTER_H_
#define CRITTER_H_

#include "game/Collidable.h"
#include "game/MovingObject.h"
namespace game {

class Critter : public Collidable, public MovingObject {
};

} /* namespace game */
#endif /* CRITTER_H_ */
