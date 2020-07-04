#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace sf;

class Character
{
	public:
		Character(Texture* texture, Vector2u imagecount, float switchtime, float speed);
		~Character();
		void update(float deltatime);
		void draw(RenderWindow &window);

		Vector2f getPosition();
		Collider getCollider();

	private:
		RectangleShape body;
		Animation animation;
		unsigned int row;
		float speed;
		bool orientation;
};

