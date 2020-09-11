#include <SFML/Graphics.hpp>
#include "globalVars.h"


class Player
{
public:
	Player(bool left);
	
	~Player();
	sf::Vector2f pos;
	sf::RectangleShape player;

	void drawTo(sf::RenderWindow &GAMEwindow);
	void move(bool left, float dt);
	bool left;


};

