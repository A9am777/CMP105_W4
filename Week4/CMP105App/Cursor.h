#pragma once
#include "Framework/GameObject.h"
class Cursor :
public GameObject
{
	public:
		Cursor();
		~Cursor();

		void handleInput(float) override;
		void update(float) override;

	private:

};

