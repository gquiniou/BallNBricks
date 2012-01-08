//============================================================================
// Name        : BallsNBricks.cpp
// Author      : greg
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "game/Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
	cout << "Hello World!!!" << endl; // prints Hello World!!!

	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "SFML Breakout");

	game::Game g(App);
	g.start();

	App.Close();

	return 0;
}
