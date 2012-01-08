/*
 * Game.h
 *
 *  Created on: 7 janv. 2012
 *      Author: greg
 */

#ifndef GAME_H_
#define GAME_H_

#include "paddle.h"
#include <SFML/Graphics.hpp>
#include <memory>


namespace game {

class Game {
public:
	Game(sf::RenderWindow &_app) : App(_app)
	{ }

	void start();

private:
	void mainloop();
	void init();
	void cleanup();

	sf::RenderWindow &App;
	std::unique_ptr<Paddle> pad;
};

} /* namespace game */
#endif /* GAME_H_ */
