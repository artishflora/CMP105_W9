#include "BulletManager.h"
#include "Bullet.h"

BulletManager::BulletManager()
{
	for (int i = 0; i < 40; i++)
	{
		bullets.push_back(Bullet());
		bullets[i].setAlive(false);
		bullets[i].setSize(sf::Vector2f(10, 5));
		bullets[i].setFillColor(sf::Color::Black);
	}
}

BulletManager::~BulletManager()
{

}

void BulletManager::spawn(sf::Vector2f playerPos, float dt)
{
	bool found = false;
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setAlive(true);
			sf::Vector2f mousepos = sf::Vector2f(input->getMouseX(), input->getMouseY());
			setSpawnPoint(playerPos);
			bullets[i].setPosition(spawnPoint);
			bullets[i].setVelocity(mousepos.x - bullets[i].getPosition().x, mousepos.y - bullets[i].getPosition().y);
			bullets[i].setVelocity(vector.normalise(bullets[i].getVelocity()) * 400.f);
			found = true;
			return;
		}
	}
	if (!found)
	{
		bullets.push_back(Bullet());
		bullets[bullets.size() - 1].setAlive(true);
		bullets[bullets.size() - 1].setSize(sf::Vector2f(10, 5));
		bullets[bullets.size() - 1].setFillColor(sf::Color::Black);
		bullets[bullets.size() - 1].setVelocity(200, 0);
		setSpawnPoint(playerPos);
		bullets[bullets.size() - 1].setPosition(spawnPoint);
	}
}

void BulletManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}
	}
	deathCheck();
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			if (bullets[i].getPosition().x < -10)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().x > window->getSize().x)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y < -5)
			{
				bullets[i].setAlive(false);
			}
			if (bullets[i].getPosition().y > window->getSize().y)
			{
				bullets[i].setAlive(false);
			}
		}
	}
}

void BulletManager::render(sf::RenderWindow* _window)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			_window->draw(bullets[i]);
		}
	}
}