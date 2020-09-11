#include "Player.h"

Player::Player(bool left)
{
	player.setSize({0.05, 0.3}); 
	player.setOrigin(0.025, 0.15); 
	if (left) 
	{
		player.setFillColor(sf::Color::Blue); 
	}

	else 
	{
		player.setFillColor(sf::Color::Green);
	}
	
	
}


void Player::drawTo(sf::RenderWindow &GAMEwindow)
{
	player.setPosition(pos);
	GAMEwindow.draw(player);
}


void Player::move(bool left, float dt)
{
	if (left)
	{
		pos.x = -0.9 * aspect;
	}
	else
	{
		pos.x = 0.9 * aspect;
	}
	if (left)
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		pos.y -= 0.5f * dt;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		pos.y += 0.5f * dt;
		
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		pos.y -= 0.5f * dt;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		pos.y += 0.5f * dt;
	}
	
	if (pos.y < -0.85) pos.y = -0.85;
	if (pos.y > 0.85) pos.y = 0.85;
}


Player::~Player()
{
}
