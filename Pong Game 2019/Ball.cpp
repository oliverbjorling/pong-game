#include "Ball.h"
#include <math.h>

Ball::Ball()
{
	sf::Image img; 
	sf::Texture texture1;
	img.loadFromFile("dvdscreen1.png");
	texture1.loadFromImage(img);
	ball.setTexture(&texture1);

	ball.setRadius(0.05);   
	ball.setOrigin(0.05, 0.05);
	ball.setFillColor(sf::Color::White);
	
	pos = { 0.05, 0 }; 
	dir = { 0.5, 0.5 }; 
}

void Ball::drawTo(sf::RenderWindow &GAMEwindow)
{
	ball.setPosition(pos);
	GAMEwindow.draw(ball);
	
}

void Ball::move(float dt) 
{
	pos.x += dir.x * dt;
	pos.y += dir.y * dt;
	
	if (pos.y < -1 + 0.05) dir.y *= -1;
	if (pos.y > 1 - 0.05) dir.y *= -1;
		
}

Ball::~Ball()
{
}
