#include "Player.h"
#include <iostream>

void Player::handleInput(float dt)
{
	setVelocity(sf::Vector2f(0, 0));
	if (input->isKeyDown(sf::Keyboard::W)) { velocity.y += -100; }
	if (input->isKeyDown(sf::Keyboard::A)) { velocity.x += -100; }
	if (input->isKeyDown(sf::Keyboard::S)) { velocity.y += 100; }
	if (input->isKeyDown(sf::Keyboard::D)) { velocity.x += 100; }
}

void Player::update(float dt)
{
	setPosition(getPosition() + getVelocity() * dt);
}

Player::Player() : GameObject()
{
	alive = true;
}

Player::~Player()
{

}
