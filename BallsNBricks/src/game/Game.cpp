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

	std::unique_ptr<Ball> ball1(new Ball(info));
	balls.push_back(std::move(ball1));
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

			}
		}

		state.mousex = sf::Mouse::GetPosition(App).x;
		paddle->update(state);

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
