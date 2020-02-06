#pragma once
#include "Framework/GameObject.h"
class Enemy:
public GameObject
{
	public:
		Enemy();
		~Enemy();

		void update(float) override;

		void setSizeArea(sf::Vector2u);

	private:
		sf::Vector2u sizeArea;
};

