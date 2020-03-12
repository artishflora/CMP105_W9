#include "BallManager.h"
#include <iostream>

BallManager::BallManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");
	spawnPoint = sf::Vector2f(350, 250);

	for (int i = 0; i < 25; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

void BallManager::spawn()
{
	found = false;
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
			balls[i].setPosition(spawnPoint);
			found = true;
			return;
		}
	}
	if (!found)
	{
		balls.push_back(Ball());
		balls[balls.size() - 1].setTexture(&texture);
		balls[balls.size() - 1].setSize(sf::Vector2f(100, 100));
		balls[balls.size() - 1].setVelocity(rand() % 200 - 100, rand() % 200 - 100);
		balls[balls.size() - 1].setPosition(spawnPoint);
		balls[balls.size() - 1].setAlive(true);

	}
}

void BallManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().x <-100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x > 800)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > 600)                       
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void BallManager::render(sf::RenderWindow* _window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			_window->draw(balls[i]);
		}
	}
}