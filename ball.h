#pragma once
#include <iostream>
#include "settings.h"
#include "SFML/Graphics.hpp"
struct Ball {
	sf::CircleShape shape;
	float speedx, speedy;
	int leftScore, rightScore;
};
void ballInit(Ball& ball) {
	ball.shape.setRadius(BALL_RADIUS);
	ball.shape.setFillColor(BALL_COLOR);
	ball.shape.setPosition(BALL_START_POS);
	float arr_speed[]{ -5.f,-4.f,-3.f,-2.f,-1.f,1.f,2.f,3.f,4.f,5.f };
	int index = rand() % 10;
	ball.speedx = arr_speed[index];
	index = rand() % 10;
	ball.speedy = arr_speed[index];
	ball.score = 0;
}
void ballUpdate(Ball& ball) {
	ball.shape.move(ball.speedx, ball.speedy);
	if (ball.shape.getPosition().x <= 0 ||
		ball.shape.getPosition().x >= WINDOW_WIDTH - 2 * BALL_RADIUS
		)
		ball.speedx = -ball.speedx;

	if (ball.shape.getPosition().y <= 0)
		ball.speedy = -ball.speedy;
}
void ballDraw(sf::RenderWindow& window, const Ball& ball) {
	window.draw(ball.shape);
}





