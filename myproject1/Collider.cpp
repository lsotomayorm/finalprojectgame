#include "Collider.h"

Collider::Collider(RectangleShape& body) : body(body) {

}

Collider::~Collider() {

}

bool Collider::checkCollision(Collider other, float push) {
	Vector2f otherposition = other.getPosition();
	Vector2f otherhalfsize = other.getHalfSize();
	Vector2f thisposition = getPosition();
	Vector2f thishalfsize = getHalfSize();

	float deltax = otherposition.x - thisposition.x;
	float deltay = otherposition.y - thisposition.y;

	float intersectx = abs(deltax) - (otherhalfsize.x + thishalfsize.x);
	float intersecty = abs(deltay) - (otherhalfsize.y + thishalfsize.y);

	if (intersectx < 0.f && intersecty < 0.f) {
		push = min(max(push, 0.f), 1.f);
		if (intersectx > intersecty) {
			if (deltax > 0.f) {
				move(intersectx * (1.f - push), 0.f);
				other.move(-intersectx * push, 0.f);
			}
			else {
				move(-intersectx * (1.f - push), 0.f);
				other.move(intersectx * push, 0.f);
			}
		}
		else {
			if (deltay > 0.f) {
				move(0.f, intersecty * (1.f - push));
				other.move(0.f, -intersecty * push);
			}
			else {
				move(0.f, -intersecty * (1.f - push));
				other.move(0.f, intersecty * push);
			}
		}
		return true;
	}
	
	return false;
}

void Collider::move(float dx, float dy) {
	body.move(dx, dy);
}

Vector2f Collider::getPosition() {
	return body.getPosition();
}

Vector2f Collider::getHalfSize() {
	return body.getSize() / 2.f;
}