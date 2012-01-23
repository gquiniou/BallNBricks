/*
 * ResourceManager.h
 *
 *  Created on: 23 janv. 2012
 *      Author: greg
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <SFML/graphics.hpp>
#include <iostream>
#include <string>
#include <map>
#include <memory>

namespace game {

class ResourceManager {
public:
	typedef std::map<std::string, std::unique_ptr<sf::Texture>> TextureMap;

	//ResourceManager();

	//virtual ~ResourceManager();

	static sf::Texture *getTexture(const std::string filename) {
		static TextureMap textures;

		TextureMap::iterator it = textures.find(filename);
		if (it == textures.end()) {
			std::unique_ptr<sf::Texture> temp(new sf::Texture);
			sf::Texture *tex = temp.get();
			if (tex->LoadFromFile(filename)) {
				textures.insert(std::pair<std::string, std::unique_ptr<sf::Texture>>(filename, std::move(temp)));
				return tex;
			} else {
				std::cerr << "could not load texture";
			}
		} else {
			std::cout << "ResourceManager: found " << filename << std::endl;
			return it->second.get();
		}
		return nullptr;
	}

};

} /* namespace game */
#endif /* RESOURCEMANAGER_H_ */
