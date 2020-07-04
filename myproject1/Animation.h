#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Animation{
	public:
		Animation(Texture *texture, Vector2u imagecount, float switchtime);
		~Animation();

		void update(int row, float deltatime, bool orientation);

	private:

	public:
		IntRect uvrect;

	private:
		Vector2u imagecount;
		Vector2u currentimage;

		float totaltime;
		float switchtime;
};

