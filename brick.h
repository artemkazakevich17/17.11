#pragma once

 struct Brick{
	sf::RectanglecleShape shape;
};
 void BrickInit(Brick& brick) {
	 brick.shape.setFillColor(BRICK_COLOR);
	 brick.shape.setPosition(BRICK_START_POS);


	 void brickDraw(sf::RenderWindow& window, const Brick & brick); {
		 window.draw(brick.shape);
	 }