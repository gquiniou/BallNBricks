/*
 * GameObjectsManager.cpp
 *
 *  Created on: 30 janv. 2012
 *      Author: greg
 */

#include "game/GameObjectsManager.h"
#include "game/ResourceManager.h"
#include "game/LevelLoader.h"
#include <iostream>

namespace game {

 void rect2lines(line (& lines)[4], const sf::FloatRect r);


sf::Vector2i intersection(line, line);
float vlength(sf::Vector2f);

//GameObjectsManager GameObjectsManager::singleton = nullptr;

void GameObjectsManager::initLevel(sf::RenderWindow &app) {
	pad.reset(new Paddle());

	//Let's start with one ball
	std::unique_ptr<Ball> ball1(new Ball());
	balls.push_back(std::move(ball1));

	LevelLoader ll("level1.txt", ResourceManager::getTexture("briques.png"));
	bricks = ll.loadLevel();

	walls.push_back(std::unique_ptr<line>(new line(0, 0, app.getSize().x, 0)));
	walls.push_back(std::unique_ptr<line>(new line(app.getSize().x , 0, app.getSize().x, app.getSize().y)));
	walls.push_back(std::unique_ptr<line>(new line(0 , app.getSize().y, 0, 0)));
	//Bottom wall
	walls.push_back(std::unique_ptr<line>(new line(app.getSize().x , app.getSize().x, 0, app.getSize().y)));

	//	walls[0] = ;
//	walls[1] = new line(app.GetWidth(), 0, app.GetWidth(), app.GetHeight());
}

void GameObjectsManager::update(gamestate &state) {
	pad.get()->update(state);
	for(auto it = balls.begin(); it != balls.end(); it++ )
		(**it).update(state);
	for(auto it = bricks.begin(); it != bricks.end(); it++ ) {
		(**it).update(state);
		if ((**it).destroyRequest())
			it = bricks.erase(it);
	}
	for(auto it = critters.begin(); it != critters.end(); it++ )
		(**it).update(state);
}

sf::Vector2f GameObjectsManager::getClosestCollision(MovingObject & obj, sf::Vector2f movement, float& distance) {
	std::cout << &obj << distance;
	return movement;
}

sf::Vector2f GameObjectsManager::getClosestCollision(line track, bool & ishorizontal, float & distance) {
	sf::Vector2f result(0,0);
	sf::Vector2f empty(0,0);
	distance = 1000000;

	for(unsigned int i = 0; i < walls.size(); i++ ) {
		sf::Vector2f point(intersection( *walls[i].get() , track));
		if (point != empty) {
			float length = vlength( point - sf::Vector2f(track.x1, track.y1));
			if (length < distance) {
				distance = length;
				result = point;
				ishorizontal = walls[i].get()->ishorizontal() ;
			}
		}
	}
	Brick *brick = nullptr;
	for(auto it = bricks.begin(); it != bricks.end(); it++) {
		if (! (**it).isalive())
			continue;
		line lines[4];
		rect2lines(lines, (**it).getRect());
		for (auto lit = std::begin(lines); lit != std::end(lines); lit++) {
			sf::Vector2f point(intersection( *lit , track));
			if (point != empty) {
				float length = vlength( point - sf::Vector2f(track.x1, track.y1));
				if (length < distance) {
					distance = length;
					result = point;
					ishorizontal = (*lit).ishorizontal();
					brick = &(**it);
				}
			}
		}
	}
	if (brick != nullptr)
		brick->hit();
	return result;
}

void rect2lines(line (& lines)[4], const sf::FloatRect r) {
	lines[0].x1 = r.left;
	lines[0].x2 = r.left + r.width;
	lines[0].y1 = r.top;
	lines[0].y2 = r.top;
	lines[1].x1 = r.left + r.width;
	lines[1].x2 = r.left + r.width;
	lines[1].y1 = r.top;
	lines[1].y2 = r.top + r.height;
	lines[2].x1 = r.left + r.width;
	lines[2].x2 = r.left;
	lines[2].y1 = r.top + r.height;
	lines[2].y2 = r.top + r.height;
	lines[2].x1 = r.left;
	lines[2].x2 = r.left;
	lines[2].y1 = r.top + r.height;
	lines[2].y2 = r.top;
}

inline float vlength(const sf::Vector2f v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

sf::Vector2i intersection(const line l1, const line l2) {
	sf::Vector2i result(0, 0);

	int denom = ((l2.y2-l2.y1) * (l1.x2-l1.x1)) - ((l2.x2-l2.x1) * (l1.y2-l1.y1));
	if (denom != 0) {
		float ua = (((l2.x2-l2.x1) * (l1.y1-l2.y1)) - ((l2.y2-l2.y1) * (l1.x1-l2.x1))) / denom;
		if ((ua >= 0) && (ua <= 1)) {
			float ub = (((l1.x2-l1.x1) * (l1.y1-l2.y1)) - ((l1.y2-l1.y1) * (l1.x1-l2.x1))) / denom;
			if ((ub >= 0) && (ub <= 1)) {
				result.x = l1.x1 + (ua * (l1.x2-l1.x1));
				result.y = l1.y1 + (ua * (l1.y2-l1.y1));
			}
		}
	}
	return result;
}


void GameObjectsManager::draw(sf::RenderWindow &App) {
	for(auto it = bricks.begin(); it != bricks.end(); it++ )
		App.draw((**it).getDrawable());
	for(auto it = critters.begin(); it != critters.end(); it++ )
		App.draw((**it).getDrawable());
	for(auto it = balls.begin(); it != balls.end(); it++ )
		App.draw((**it).getDrawable());
	App.draw(pad.get()->getDrawable());
}
} /* namespace game */


