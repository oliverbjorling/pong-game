
#include <SFML/Graphics.hpp>

#include "globalVars.h"

class Ball
{
public:
	Ball();
	~Ball();
	sf::Vector2f pos;
	sf::CircleShape ball;
	sf::Vector2f dir;
	void drawTo(sf::RenderWindow &GAMEwindow);
	void move(float dt);

};

