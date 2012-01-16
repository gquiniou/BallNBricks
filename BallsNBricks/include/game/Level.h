/*
 * Level.h
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>


namespace game {

class Level {
public:
	Level(std::string path);
	virtual ~Level();
private:
	std::ifstream levelfile;
	std::string filepath;
	sf::Texture texture;
};

} /* namespace game */
#endif /* LEVEL_H_ */
