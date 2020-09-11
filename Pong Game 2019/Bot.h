#pragma once

#include <SFML/Graphics.hpp>
#include "globalVars.h"
#include "Ball.h"


class Bot
{
public:
	Bot(bool botLeft);

	~Bot();
	sf::Vector2f pos;
	sf::RectangleShape bot;

	void drawTo(sf::RenderWindow &GAMEwindow);
	void move(bool botLeft, Ball &ball, float dt);
	bool botLeft;

};

