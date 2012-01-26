/*
 * Game.h
 *
 *  Created on: 7 janv. 2012
 *      Author: greg
 */

#ifndef GAME_H_
#define GAME_H_

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "LevelLoader.h"
#include "gamestate.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <list>


namespace game {

class Game {

public:

	Game(sf::RenderWindow &_app) : App(_app) {}

	//sf::Vector2f GetClosestCollision(const GameObject *,const line, bool &);

	void start();

private:

	void mainloop();
	void init();
	void cleanup();

	sf::RenderWindow &App;
	std::unique_ptr<Paddle> pad;
	std::list<std::unique_ptr<Ball>> balls;
	std::list<std::unique_ptr<Brick>> bricks;
	sf::Texture brickstexture;
	gamestate state;
};

} /* namespace game */
#endif /* GAME_H_ */
