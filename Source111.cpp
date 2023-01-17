#include "settings.h"
#include "founctions.h"
#include "bat.h"
#include "text.h"
using namespace sf;

int main()
{
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE
	);
	Bat bat;
	batInit(bat);
	Ball ball;
	ballInit(ball);
	TextObj scoreText;
	textInit(scoreText, );
	while (window.isOpen())
	{
		checkEvents(window);
		updateGame(bat, ball, scoreText, score);
		//����� ���������? - �������� ����
		if (ball.shape.getPosition().y >=
			WINDOW_HEIGHT - 2 * BALL_RADIUS)
			break;)
		checkCollisions(bat, ball);
		drawGame(window, bat, ball);
	}
	
	return 0;
}