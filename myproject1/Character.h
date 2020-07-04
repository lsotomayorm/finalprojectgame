#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"

using namespace sf;

class Character
{
	public:
		Character(Texture* texture, Vector2u imagecount, float switchtime, float speed);
		~Character();
		void update(float deltatime);
		void draw(RenderWindow &window);

	private:
		RectangleShape body;
		Animation animation;
		unsigned int row;
		float speed;
		bool orientation;
};

