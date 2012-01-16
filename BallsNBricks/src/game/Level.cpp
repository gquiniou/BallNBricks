/*
 * Level.cpp
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#include "game/Level.h"


namespace game {

Level::Level(std::string path)  : filepath(path) {
	// TODO Auto-generated constructor stub
	filepath = path;

	levelfile.open(filepath, std::ios::in );
	if (! texture.LoadFromFile("bricks.png"))
		throw std::exception();

}

Level::~Level() {
	// TODO Auto-generated destructor stub
	if (levelfile.is_open())
		levelfile.close();
}


} /* namespace game */
