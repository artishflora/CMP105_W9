#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	fallingManager.setWindow(window);

	player.setSize(sf::Vector2f(50, 100));
	player.setFillColor(sf::Color::Magenta);
	player.setInput(input);
	player.setWindow(window);

	bulletManager.setWindow(window);
	bulletManager.setInput(input);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::S))
	{
		input->setKeyUp(sf::Keyboard::S);
		ballManager.spawn();
	}
	if (input->isKeyDown(sf::Keyboard::Enter))
	{
		input->setKeyUp(sf::Keyboard::Enter);
		fallingManager.spawn();
	}

	player.handleInput(dt);

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		bulletManager.spawn(player.getPosition(), dt);
	}
}

// Update game objects
void Level::update(float dt)
{
	ballManager.update(dt);
	fallingManager.update(dt);
	bulletManager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	ballManager.render(window);
	fallingManager.render(window);

	window->draw(player);
	bulletManager.render(window);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}