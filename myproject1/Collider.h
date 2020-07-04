#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"

using namespace sf;
using namespace std;

class Collider{
	public:
		Collider(RectangleShape& body);
		~Collider();

		void move(float dx, float dy);

		bool checkCollision(Collider other, float push);
		Vector2f getPosition();
		Vector2f getHalfSize();
	private:
		RectangleShape& body;
};

