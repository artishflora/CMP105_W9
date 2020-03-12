#include "Player.h"

Player::Player()
{
	speed = 200;
	setPosition(400, 300);
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	if (getPosition().y > window->getSize().y - 100) {}
	else if (input->isKeyDown(sf::Keyboard::Down))
	{
		move(0, speed * dt);
	}
	if (getPosition().y < 0) {}
	else if (input->isKeyDown(sf::Keyboard::Up))
	{
		move(0, -(speed * dt));
	}
	if (getPosition().x < 0) {}
	else if (input->isKeyDown(sf::Keyboard::Left))
	{
		move(-(speed * dt), 0);
	}
	if (getPosition().x > window->getSize().x - 50) {}
	else if (input->isKeyDown(sf::Keyboard::Right))
	{
		move(speed * dt, 0);
	}
}
