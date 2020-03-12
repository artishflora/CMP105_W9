#pragma once
#include <vector>
#include "Ball.h"
#include <math.h>

class FallingManager
{
	private:
		std::vector<Ball> balls;
		sf::Vector2f spawnPoint;
		sf::Texture texture;
		sf::RenderWindow* window;

	public:
		FallingManager();
		~FallingManager();

		void spawn();
		void update(float dt);
		void deathCheck();
		void render(sf::RenderWindow* _window);
		void setWindow(sf::RenderWindow* win) { window = win; };
		void setSpawnPoint() { spawnPoint = sf::Vector2f(rand() % (window->getSize().x-100) + 0, -100); }
};

