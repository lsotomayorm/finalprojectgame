#include "Character.h"

Character::Character(Texture* texture, Vector2u imagecount, float switchtime, float speed) : animation(texture, imagecount, switchtime) {
	this->speed = speed;
	row = 0;
	orientation = true;

	body.setSize(Vector2f(100.f, 150.f));
	body.setPosition(256.f, 256.f);
	body.setTexture(texture);
}

Character::~Character() {

}

void Character::update(float deltatime) {
	Vector2f movement(0.f, 0.f);
	if (Keyboard::isKeyPressed(Keyboard::A))
		movement.x -= speed * deltatime;
	if (Keyboard::isKeyPressed(Keyboard::D))
		movement.x += speed * deltatime;
	if (movement.x == 0.f) {
		row = 0;
	}
	else {
		row = 1;
		if (movement.x > 0.f)
			orientation = true;
		else
			orientation = false;
	}
	animation.update(row,deltatime,orientation);
	body.setTextureRect(animation.uvrect);
	body.move(movement);
}

void Character::draw(RenderWindow &window) {
	window.draw(body);
}