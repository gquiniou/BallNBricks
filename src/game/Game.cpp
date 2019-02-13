/*
 * Game.cpp
 *
 *  Created on: 7 janv. 2012
 *      Author: greg
 */

#include "game/Game.h"
#include "game/ResourceManager.h"
#include "game/LevelLoader.h"
#include <iostream>
#include <typeinfo>

namespace game {


void Game::start() {
	std::cout << "started" << std::endl;

	init();
	mainloop();
	cleanup();
}

void Game::init() {
	App.setMouseCursorVisible(false);
	App.setVerticalSyncEnabled(true);

	pad.reset(new Paddle());

	//Let's start with one ball
	std::unique_ptr<Ball> ball1(new Ball());
	balls.push_back(std::move(ball1));

	state.ballfired = false;

	//Bottom wall
	state.walls[1].x1 = 0;
	state.walls[1].y1 = state.walls[1].y2 = App.getSize().y;
	state.walls[1].x2 = App.getSize().x;
	//Right wall
	state.walls[2].x1 = state.walls[2].x2 =  App.getSize().x;
	state.walls[2].y1 = 0;
	state.walls[2].y2 = App.getSize().y;
	//left wall
	state.walls[3].x1 = state.walls[3].x2 = 0;
	state.walls[3].y1 = 0;
	state.walls[3].y2 = App.getSize().y;
	//top wall
	state.walls[4].x1 = 0;
	state.walls[4].y1 = state.walls[4].y2 = 0;
	state.walls[4].x2 =  App.getSize().x;

	//brickstexture.LoadFromFile("briques.png");
	LevelLoader ll("level1.txt", ResourceManager::getTexture("briques.png"));
	bricks = ll.loadLevel();
}

void Game::cleanup() {

}

void Game::mainloop() {

	sf::Clock clock;
	Paddle *paddle = pad.get();

	while (App.isOpen()) {

		sf::Event Event;
		while (App.pollEvent(Event)) {
			if ((Event.type == sf::Event::Closed) || ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))) {
				return;
			}
			if (Event.type == sf::Event::MouseButtonReleased && Event.mouseButton.button == sf::Mouse::Button::Left) {
				state.ballfired = true;
			}
			if (Event.type == sf::Event::MouseButtonReleased && Event.mouseButton.button == sf::Mouse::Button::Right) {
				std::unique_ptr<Ball> tmp(new Ball());
				balls.push_back(std::move(tmp));
			}
		}

		state.frametime = clock.restart();
		state.mousex = sf::Mouse::getPosition(App).x;

		paddle->update(state);

		state.paddleRect = paddle->getDrawable().getGlobalBounds();
		//The paddle is a moving wall
		state.walls[0].x1 = state.paddleRect.left;
		state.walls[0].y1 = state.walls[0].y2 = state.paddleRect.top;
		state.walls[0].x2 = state.paddleRect.left + state.paddleRect.width;

		for(auto it = balls.begin(); it != balls.end(); it++ )
			(**it).update(state);
		//	std::cout << typeid(**it).name() << std::endl;



		App.clear();

		App.draw(paddle->getDrawable());
		for (auto it = begin(balls); it != end(balls); it++)
			App.draw((**it).getDrawable());
		for (auto it = begin(bricks); it != end(bricks); it++)
			App.draw((**it).getDrawable());
		App.display();
	}
}

//sf::Vector2f Game::GetClosestCollision(const GameObject *source, const line track, bool &horizbounce) {
//	//for (auto it = begin(bricks); it != end(bricks); it++)
//}


} /* namespace game */
