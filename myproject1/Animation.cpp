#include "Animation.h"

Animation::Animation(Texture* texture, Vector2u imagecount, float switchtime) {
	this->imagecount = imagecount;
	this->switchtime = switchtime;
	totaltime = 0.f;
	currentimage.x = 0;

	uvrect.width = texture->getSize().x / float(imagecount.x);
	uvrect.height = texture->getSize().y / float(imagecount.y);
}

Animation::~Animation(){
}

void Animation::update(int row, float deltatime, bool orientation) {
	currentimage.y = row;
	totaltime += deltatime;

	if (totaltime >= switchtime) {
		totaltime -= switchtime;
		currentimage.x++;

		if (currentimage.x >= imagecount.x) {
			currentimage.x = 0;
		}
	}
	uvrect.top = currentimage.y * uvrect.height;

	if (orientation) {
		uvrect.left = currentimage.x * uvrect.width;
		uvrect.width = abs(uvrect.width);
	}
	else {
		uvrect.left = (currentimage.x + 1)  * abs(uvrect.width);
		uvrect.width = -abs(uvrect.width);
	}
}