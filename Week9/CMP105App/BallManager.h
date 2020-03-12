#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>

class BallManager
{
	private:
		std::vector<Ball> balls;
		sf::Vector2f spawnPoint;
		sf::Texture texture;
		bool found;
		//sf::RenderWindow* window;

	public:
		BallManager();
		~BallManager();

		void spawn();
		void update(float dt);
		void deathCheck();
		void render(sf::RenderWindow* _window);
		//void setWindow(sf::RenderWindow* win) { window = win; };
		//void setSpawnPoint() { spawnPoint = sf::Vector2f((window->getSize().x / 2) - 50, (window->getSize().y / 2) - 50); }
};

