#pragma once
#include <SFML\Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace sf;

class Platform{
	public:
		Platform(Texture * texture,Vector2f size,Vector2f position);
		~Platform();

		void draw(RenderWindow& window);
		Collider getCollider();
	private:
		RectangleShape body;
};

