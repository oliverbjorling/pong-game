#include <SFML/Graphics.hpp>
#include <iostream>
#include "SFML/Window.hpp"
#include <thread>
#include <chrono>
#include <cstdlib>  
#include <random>

#include "globalVars.h"
#include "Player.h"
#include "Ball.h"
#include "Bot.h"
#include "EscapeMenu.h"


Player left(1); 
Player right(0);
Ball ball;
Bot botleft(1);
Bot botright(0);
EscapeMenu EscMenu;


int ScoreRight = 0;
int ScoreLeft = 0;


float Randf(float min, float max) 
{
	return min + static_cast<float>(rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

std::string Collision()
{
	//left Player
	if ((ball.pos.y < left.pos.y + 0.20) && (ball.pos.y > left.pos.y - 0.20) && (ball.pos.x < left.pos.x + 0.05) && (ball.pos.x > left.pos.x - 0.05)) 
	{
		ball.dir.x *= -1;
		ball.pos.x = left.pos.x + 0.05;
	}

	//right Player
	if ((ball.pos.y < right.pos.y + 0.20) && (ball.pos.y > right.pos.y - 0.20) && (ball.pos.x > right.pos.x - 0.05) && (ball.pos.x < right.pos.x + 0.05)) 
	{
		ball.dir.x *= -1;
		ball.pos.x = right.pos.x - 0.05;
	}

	//left Bot
	if ((ball.pos.y < botleft.pos.y + 0.20) && (ball.pos.y > botleft.pos.y - 0.20) && (ball.pos.x < botleft.pos.x + 0.05) && (ball.pos.x > botleft.pos.x - 0.05))
	{
		ball.dir.x *= -1;
		ball.pos.x = botleft.pos.x + 0.05;
	}

	//right Bot
	if ((ball.pos.y < botright.pos.y + 0.20) && (ball.pos.y > botright.pos.y - 0.20) && (ball.pos.x > botright.pos.x - 0.05) && (ball.pos.x < botright.pos.x + 0.05))
	{
		ball.dir.x *= -1;
		ball.pos.x = botright.pos.x - 0.05;
	}

	if (ball.pos.x < -1 * aspect) 
	{
		ball.pos = { 0, Randf(-0.85, 0.85)};
		ScoreLeft++;
	}
	if (ball.pos.x > 1 * aspect) 
	{
		ball.pos = { 0, Randf(-0.85, 0.85)};
		ScoreRight++;
	}
	return ((std::to_string(ScoreLeft) + ",") + std::to_string(ScoreRight));
}



int main() 
{
	
	srand(time(0)); 
	sf::RenderWindow GAMEwindow(sf::VideoMode(width, height), "Pong Game", sf::Style::Default); 
	int ready = 1;
	
	
	sf::Image img; //ändrar iconen (kan ha vilken bild som helst.)
	img.loadFromFile("dvdscreen1.png");
	GAMEwindow.setIcon(img.getSize().x, img.getSize().y, img.getPixelsPtr()); 

	sf::View GameView(sf::Vector2f(0, 0), sf::Vector2f(2.f * aspect, 2.f)); 
	GAMEwindow.setView(GameView);
	

	sf::Text ScoreRight;
	sf::Text ScoreLeft;
	sf::Font arial;

	sf::Text counter;

	arial.loadFromFile("arial.ttf");

	ScoreLeft.setFont(arial);
	ScoreLeft.setCharacterSize(100);
	ScoreLeft.setScale(1.f / 500, 1.f / 500);
	ScoreLeft.setFillColor(sf::Color::White);
	ScoreLeft.setPosition(0.25f, -1);

	ScoreRight.setFont(arial);
	ScoreRight.setCharacterSize(100);
	ScoreRight.setScale(1.f / 500, 1.f / 500);
	ScoreRight.setFillColor(sf::Color::White);
	ScoreRight.setPosition(-0.25f, -1);

	GAMEwindow.setFramerateLimit(60); 
	
	float speedValue = 2;
	float speedMult = speedValue;
	sf::Clock clock; 
	while (GAMEwindow.isOpen()) 
	{
		int escapeButtonUSE = 1;
		float dt = clock.restart().asSeconds() * speedMult;
		sf::Event closeWindow;
		while (GAMEwindow.pollEvent(closeWindow)) 
		{
			if (closeWindow.type == sf::Event::Closed)
				GAMEwindow.close(); 

			if (closeWindow.type == sf::Event::Resized) 
			{
				
				width = GAMEwindow.getSize().x;
				height = GAMEwindow.getSize().y;
				aspect = width / height;
				GameView.setSize(sf::Vector2f(2.f * aspect, 2.f));
				GAMEwindow.setView(GameView);
				dt = 0;

			}
			
			

			if (closeWindow.type == sf::Event::KeyPressed)  
			{
				
				if (closeWindow.key.code == sf::Keyboard::Escape) 
				{
					
					if (speedMult == speedValue) 
					{
						speedMult = 0;

					}
					else 
					{
						speedMult = speedValue;
					}


				}

			if (closeWindow.key.code == sf::Keyboard::Delete) 
			{
				GAMEwindow.close();
			}

			}
		}

		ball.move(dt);

		left.move(1, dt);


		right.move(0, dt);


		botleft.move(1, ball, dt);


		botright.move(0, ball, dt);
		

		if (GAMEwindow.isOpen()) 
		{
			if (dt==0) 
			{
				EscMenu.drawTo(GAMEwindow);
			}
			else 
			{

				GAMEwindow.clear();

				std::string score = Collision(); 
				int comma = score.find(',');
				std::string LeftScore = score.substr(0, comma);
				std::string RightScore = score.substr(comma + 1, score.length() - (comma));
				std::cout << RightScore << LeftScore << std::endl;

				ScoreRight.setString(RightScore);
				ScoreLeft.setString(LeftScore);

				GAMEwindow.draw(ScoreLeft);
				GAMEwindow.draw(ScoreRight);

				ball.drawTo(GAMEwindow);

				botright.drawTo(GAMEwindow);

				//right.drawTo(GAMEwindow);

				//left.drawTo(GAMEwindow);

				botleft.drawTo(GAMEwindow);
			}

		}
		
			//GAMEwindow.clear();

			GAMEwindow.display();
			
			while (ready >= 1) 
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
				ready -= 1;
				clock.restart(); 
			}

	}
	
}

