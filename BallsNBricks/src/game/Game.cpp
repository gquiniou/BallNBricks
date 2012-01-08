/*
 * Game.cpp
 *
 *  Created on: 7 janv. 2012
 *      Author: greg
 */

#include "game/Game.h"
#include <iostream>

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

		paddle->update(sf::Mouse::GetPosition(App).x);

		App.Clear();

		App.Draw(paddle->getDrawable());
		App.Display();
	}
}

} /* namespace game */
