#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	window->setMouseCursorVisible(false);

	texture.loadFromFile("gfx/Mushroom.png");
	textureEnemy.loadFromFile("gfx/goomba.png");
	cursTex.loadFromFile("gfx/icon.png");
	levelTex.loadFromFile("gfx/Level1_1.png");

	player.setInput(input);
	player.setTexture(&texture,false);
	player.setPosition(sf::Vector2f(0, 0));
	player.setSize(sf::Vector2f(100, 100));

	goomba.setTexture(&textureEnemy, false);
	goomba.setPosition(sf::Vector2f(250, 100));
	goomba.setSize(sf::Vector2f(100, 100));
	goomba.setVelocity(sf::Vector2f(100,50));

	goomba.setSizeArea(window->getSize());

	evilMushroom.setTexture(&texture, false);
	evilMushroom.setPosition(sf::Vector2f(50, 250));
	evilMushroom.setSize(sf::Vector2f(50, 50));
	evilMushroom.setVelocity(sf::Vector2f(-100, 50));

	evilMushroom.setSizeArea(window->getSize());

	curs.setInput(input);
	curs.setTexture(&cursTex, false);
	curs.setSize(sf::Vector2f(50, 50));

	b.setTexture(&levelTex, false);
	b.setSize(sf::Vector2f(11038,675));
	b.setPosition(sf::Vector2f(0, 0));

	camera.setSizeArea(sf::Vector2u(11038, 675));
	camera.setSize(sf::Vector2f(window->getSize().x,window->getSize().y));
	camera.setPosition(sf::Vector2f(0, 0));
	camera.setVelocity(sf::Vector2f(0, 0));
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	camera.setVelocity(sf::Vector2f(0, 0));
	if (input->isKeyDown(sf::Keyboard::Q)) { camera.setVelocity(sf::Vector2f(-100,0)); }
	if (input->isKeyDown(sf::Keyboard::E)) { camera.setVelocity(sf::Vector2f(100, 0)); }
	if (input->isKeyDown(sf::Keyboard::R)) { camera.setVelocity(sf::Vector2f(0, -100)); }
	if (input->isKeyDown(sf::Keyboard::F)) { camera.setVelocity(sf::Vector2f(0, 100)); }

	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	player.update(dt);
	goomba.update(dt);
	evilMushroom.update(dt);
	curs.update(dt);
	camera.update(dt);
	sf::View v = window->getView();
	v.setCenter(sf::Vector2f(camera.getPosition().x + camera.getSize().x/2, camera.getPosition().y + camera.getSize().y/2));
	window->setView(v);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(b);
	window->draw(player);
	window->draw(goomba);
	window->draw(evilMushroom);
	window->draw(curs);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}