#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::update(float dt)
{
	if (getPosition().x + getSize().x > sizeArea.x) { velocity.x = -velocity.x; setPosition(sf::Vector2f(sizeArea.x - getSize().x, getPosition().y)); }
	if (getPosition().y + getSize().y > sizeArea.y) { velocity.y = -velocity.y; setPosition(sf::Vector2f(getPosition().x, sizeArea.y - getSize().y)); }
	if (getPosition().x < 0) { velocity.x = -velocity.x; setPosition(0, getPosition().y); }
	if (getPosition().y < 0) { velocity.y = -velocity.y; setPosition(getPosition().x, 0); }

	setPosition(getPosition() + getVelocity() * dt);
}

void Enemy::setSizeArea(sf::Vector2u newArea)
{
	sizeArea = newArea;
}
