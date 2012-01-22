/*
 * Level.cpp
 *
 *  Created on: 15 janv. 2012
 *      Author: greg
 */

#include "game/LevelLoader.h"


namespace game {

LevelLoader::LevelLoader(std::string path, gameinfo i, sf::Texture *brickstexture)  : filepath(path), infos(i), texture(brickstexture) {
	// TODO Auto-generated constructor stub
	filepath = path;

	levelfile.open(filepath, std::ios::in );
	if (! levelfile.is_open())
		throw std::exception();
}
std::list<std::unique_ptr<Brick>> LevelLoader::loadLevel() {
	std::list<std::unique_ptr<Brick>> bricks;
	char line[256];
	int y = 0;

	while (! levelfile.eof()) {

		levelfile.getline(line, 256);

		if (line[0] == ';')
			continue;

		int x = 0;
		char prev = 0;
		for (char* c = line ; *c != 0 ; c++) {
			if (*c != '0' && *c != prev) {
				sf::Sprite sprite(*texture);
				switch (*c) {
				case '1':
					sprite.SetTextureRect(sf::IntRect(48, 0, 48, 16));
					break;
				case '2':
					sprite.SetTextureRect(sf::IntRect(96, 0, 32, 16));
					break;
				case '3':
					sprite.SetTextureRect(sf::IntRect(128, 0, 16, 16));
					break;
				default:
				continue;
				}
				sprite.SetPosition(x, y);
				std::unique_ptr<Brick> temp(new Brick(infos, sprite));
				bricks.push_back(std::move(temp));
			}
			prev = *c;
			x += 16;
		}
		y += 16;
	}
	return bricks;
}

LevelLoader::~LevelLoader() {
	// TODO Auto-generated destructor stub
	if (levelfile.is_open())
		levelfile.close();
}


} /* namespace game */
