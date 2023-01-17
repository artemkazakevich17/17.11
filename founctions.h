#pragma once
#include "SFML/Graphics.hpp"
#include "bat.h"
#include "ball.h"

void checkEvents(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();

	}
}
	void batInit(Bat& bat) {
		bat.shape.setSize(sf::Vector2f(BAT_WIDTH, BAT_HEIGHT));
		bat.shape.setFillColor(BAT_COLOR);
		bat.shape.setPosition(BAT_START_POS);
		bat.speedx = 0.f;
	}
	
	void bat_Control(Bat& bat) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) bat.speedx = -BAT_SPEED;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) bat.speedx = BAT_SPEED;
		bat.shape.move(bat.speedx, 0.f);
		bat.speedx = 0.f;
	}
	void batReboundEdges(Bat& bat) {
		float batx = bat.shape.getPosition().x;
		float baty = bat.shape.getPosition().y;
		if (batx <= 0)bat.shape.setPosition(0.f, baty);
		if (batx >= WINDOW_WIDTH - BAT_WIDTH)
			bat.shape.setPosition(WINDOW_WIDTH - BAT_WIDTH, baty);
	}
	void batUpdate(Bat& bat) {
		bat_Control(bat);
		batReboundEdges(bat);
	}
void updateGame(Bat& bat, Ball& ball) {
	batUpdate(bat);
	ballUpdate(ball);

}
void checkCollisions(Bat& bat, Ball& ball) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
}
if (pointInRect(bat.shape, midBottom)) {

}
//кто в кого попал , пересекся и что с этим делать
void drawGame(sf::RenderWindow& window, Bat& bat) {
	window.clear();
	window.draw(bat.shape);
	window.display();
}



