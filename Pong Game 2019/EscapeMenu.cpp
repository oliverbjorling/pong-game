#include "EscapeMenu.h"


EscapeMenu::EscapeMenu()
{
	escapeMenu.setSize({ width, height });
	escapeMenu.setFillColor(sf::Color::Transparent);
	escapeMenu.setOrigin(2 * aspect, 2 * aspect);
	
}

void EscapeMenu::drawTo(sf::RenderWindow &GAMEwindow)
{
	escapeMenu.setPosition(pos);
	GAMEwindow.draw(escapeMenu);
}

void EscapeMenu::placed(float dt) 
{
	pos.y = dt;
	pos.x = dt;
}

EscapeMenu::~EscapeMenu()
{
}
