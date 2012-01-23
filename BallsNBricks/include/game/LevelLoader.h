/*
 * Level.h
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "game/Brick.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include <memory>
#include <list>


namespace game {

class LevelLoader {
public:
	LevelLoader(std::string path, gameinfo i, sf::Texture *brickstexture);
	std::list<std::unique_ptr<Brick>> loadLevel();
	virtual ~LevelLoader();
private:
	std::ifstream levelfile;
	std::string filepath;
	gameinfo infos;
	sf::Texture *texture;
};

} /* namespace game */
#endif /* LEVEL_H_ */