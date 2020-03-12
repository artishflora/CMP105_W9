#pragma once
#include "Framework/GameObject.h"
class Player :
	public GameObject
{
	private:
		int speed;
		sf::RenderWindow* window;

	public:
		Player();
		~Player();

		void handleInput(float dt) override;
		void setWindow(sf::RenderWindow* win) { window = win; };
};

