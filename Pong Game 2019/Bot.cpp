#include "Bot.h"


Bot::Bot(bool botLeft)
{
	bot.setSize({ 0.05, 0.3 });
	bot.setFillColor(sf::Color::White);
	bot.setOrigin(0.025, 0.15);

}

void Bot::drawTo(sf::RenderWindow &GAMEwindow)
{
	bot.setPosition(pos);
	GAMEwindow.draw(bot);
}

void Bot::move(bool botLeft, Ball &ball, float dt) 
{
	if (botLeft) 
	{
		pos.x = -0.9 * aspect;
	}

	else 
	{
		pos.x = 0.9 * aspect;
	}

	if (botLeft) 
	{
		if (pos.y > ball.pos.y)
		{
			pos.y -= 0.43f * dt; 
		}
		if (pos.y < ball.pos.y)
		{
			pos.y += 0.43f * dt;
		}
	}

	else 
	{
		if (pos.y > ball.pos.y)
		{
			pos.y -= 0.43f * dt;
		}
		if (pos.y < ball.pos.y)
		{
			pos.y += 0.43f * dt;
		}
	}

	if (pos.y < -0.85) pos.y = -0.85;
	if (pos.y > 0.85) pos.y = 0.85;
}

Bot::~Bot()
{
}
