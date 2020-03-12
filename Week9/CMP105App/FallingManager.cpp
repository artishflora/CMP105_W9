#include "FallingManager.h"

FallingManager::FallingManager()
{
	texture.loadFromFile("gfx/Beach_Ball.png");

	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

FallingManager::~FallingManager()
{

}

void FallingManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setVelocity(0, rand() % 600 + 300);
			setSpawnPoint();
			balls[i].setPosition(spawnPoint);
			return;
		}
	}
}

void FallingManager::update(float dt)
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

void FallingManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			if (balls[i].getPosition().y < -100)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > window->getSize().y)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void FallingManager::render(sf::RenderWindow* _window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			_window->draw(balls[i]);
		}
	}
}