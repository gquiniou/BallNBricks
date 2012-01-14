/*
 * Game.cpp
 *
 *  Created on: 7 janv. 2012
 *      Author: greg
 */

#include "game/Game.h"
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
	App.ShowMouseCursor(false);
	App.EnableVerticalSync(true);

	gameinfo info;
	info.height = App.GetHeight();
	info.width = App.GetWidth();

	pad.reset(new Paddle(info));

	//Let's start with one ball
	std::unique_ptr<Ball> ball1(new Ball(info));
	balls.push_back(std::move(ball1));

	//left wall
	state.walls[0].x1 = state.walls[0].x2 = 0;
	state.walls[0].y1 = 0;
	state.walls[0].y2 = App.GetHeight();
	//top wall
	state.walls[1].x1 = 0;
	state.walls[1].y1 = state.walls[1].y2 = 0;
	state.walls[1].x2 = App.GetWidth();
	//Right wall
	state.walls[2].x1 = state.walls[2].x2 = App.GetWidth();
	state.walls[2].y1 = 0;
	state.walls[2].y2 = App.GetHeight();

}

void Game::cleanup() {

}

void Game::mainloop() {

	Paddle *paddle = pad.get();

	while (App.IsOpened()) {

		sf::Event Event;
		while (App.PollEvent(Event)) {
			if ((Event.Type == sf::Event::Closed) || ((Event.Type == sf::Event::KeyPressed) && (Event.Key.Code == sf::Keyboard::Escape))) {
				return;
			}
			if (Event.Type == sf::Event::MouseButtonReleased) {
				state.ballfired = true;
			}
		}

		state.frametime = App.GetFrameTime();
		state.mousex = sf::Mouse::GetPosition(App).x;

		paddle->update(state);

		state.paddleRect = paddle->getRect();
		//The paddle is a moving wall
		state.walls[3].x1 = state.paddleRect.Left;
		state.walls[3].y1 = state.walls[3].y2 = state.paddleRect.Top;
		state.walls[3].x2 = state.paddleRect.Left + state.paddleRect.Width;

		for(auto it = balls.begin(); it != balls.end(); it++ )
			(**it).update(state);
		//	std::cout << typeid(**it).name() << std::endl;



		App.Clear();

		App.Draw(paddle->getDrawable());
		for (auto it = begin(balls); it != end(balls); it++)
			App.Draw((**it).getDrawable());
		App.Display();
	}
}

} /* namespace game */
