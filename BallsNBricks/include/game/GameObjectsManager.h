/*
 * GameObjectsManager.h
 *
 *  Created on: 30 janv. 2012
 *      Author: greg
 */

#ifndef GAMEOBJECTSMANAGER_H_
#define GAMEOBJECTSMANAGER_H_

#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "Critter.h"
#include <list>
#include <memory>
#include <iostream>

namespace game {

class GameObjectsManager {

public:

	static GameObjectsManager *getInstance() {
		static std::unique_ptr<GameObjectsManager> singleton;
		if (singleton.get() == nullptr) {
			std::cout << "c null"<< std::endl;
			singleton.reset(new GameObjectsManager());
		}
		return singleton.get();
	}

	~GameObjectsManager() {}

	sf::Vector2f getClosestCollision(line track, bool &ishorizontal, float &distance);
	void initLevel(sf::RenderWindow &);
	void nextlevel();
	void update(gamestate &);
	void draw(sf::RenderWindow &App);
	void pause();

	GameObject *getPaddle() {
		return pad.get();
	}

private:
	GameObjectsManager()  {}

	std::unique_ptr<Paddle> pad;
	std::list<std::unique_ptr<Ball>> balls;
	std::list<std::unique_ptr<Brick>> bricks;
	std::list<std::unique_ptr<Critter>> critters;
	std::vector<std::unique_ptr<line> > walls;

	std::string currentlevel;
	bool paused;



};

} /* namespace game */
#endif /* GAMEOBJECTSMANAGER_H_ */
