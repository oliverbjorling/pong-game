#include "globalVars.h"
#include <SFML/Graphics.hpp>


class EscapeMenu
{
public:
	EscapeMenu();
	~EscapeMenu();

	sf::Vector2f pos;
	sf::RectangleShape escapeMenu;

	void drawTo(sf::RenderWindow &GAMEwindow);
	void placed(float dt);

};

