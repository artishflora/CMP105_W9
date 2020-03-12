#pragma once
#include "Framework/GameObject.h"
class Bullet :
	public GameObject
{
	private:

	public:
		Bullet();
		~Bullet();

		void update(float dt) override;
};

