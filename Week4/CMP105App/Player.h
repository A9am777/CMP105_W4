#pragma once
#include "Framework/GameObject.h"
class Player:
public GameObject
{
	public:
		void handleInput(float dt) override;
		void update(float dt) override;
		Player();
		~Player();

	private:
		
};

