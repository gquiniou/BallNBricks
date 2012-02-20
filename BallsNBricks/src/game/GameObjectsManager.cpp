/*
 * GameObjectsManager.cpp
 *
 *  Created on: 30 janv. 2012
 *      Author: greg
 */

#include "game/GameObjectsManager.h"
#include "game/ResourceManager.h"
#include "game/LevelLoader.h"


namespace game {

//GameObjectsManager GameObjectsManager::singleton = nullptr;

void GameObjectsManager::initLevel() {
	pad.reset(new Paddle());

	//Let's start with one ball
	std::unique_ptr<Ball> ball1(new Ball());
	balls.push_back(std::move(ball1));

	LevelLoader ll("level1.txt", ResourceManager::getTexture("briques.png"));
	bricks = ll.loadLevel();

}

void GameObjectsManager::update(gamestate &state) {
	pad.get()->update(state);
	for(auto it = balls.begin(); it != balls.end(); it++ )
		(**it).update(state);
	for(auto it = bricks.begin(); it != bricks.end(); it++ )
		(**it).update(state);
	for(auto it = critters.begin(); it != critters.end(); it++ )
		(**it).update(state);
}

void GameObjectsManager::draw(sf::RenderWindow &App) {
	for(auto it = bricks.begin(); it != bricks.end(); it++ )
		App.Draw((**it).getDrawable());
	for(auto it = critters.begin(); it != critters.end(); it++ )
		App.Draw((**it).getDrawable());
	for(auto it = balls.begin(); it != balls.end(); it++ )
		App.Draw((**it).getDrawable());
	App.Draw(pad.get()->getDrawable());
}
} /* namespace game */


