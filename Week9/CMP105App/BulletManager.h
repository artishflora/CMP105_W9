#pragma once
#include <vector>
#include "Bullet.h"
#include <math.h>
#include "Framework/Vector.h"

class BulletManager
{
	private:	
		std::vector<Bullet> bullets;
		sf::RenderWindow* window;
		sf::Vector2f spawnPoint;
		Input* input;
		Vector vector;

	public:
		BulletManager();
		~BulletManager();

		void spawn(sf::Vector2f playerPos, float dt);
		void update(float dt);
		void deathCheck();
		void render(sf::RenderWindow* _window);
		void setWindow(sf::RenderWindow* win) { window = win; };
		void setSpawnPoint(sf::Vector2f _playerPos) { spawnPoint = sf::Vector2f(_playerPos.x + 50, _playerPos.y + 30); }
		void setInput(Input* in) { input = in; };
};

