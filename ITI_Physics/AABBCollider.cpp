#include "AABBCollider.h"

void AABBCollider::updatePosition(Vector2d position)
{
	Vector2d delta = position - this->position;
	ul += delta;
	lr += delta;
	this->position = position;
}

bool AABBCollider::checkCollision(AABBCollider other)
{
	if (ul.x <= other.lr.x && lr.x >= other.ul.x && ul.y <= other.lr.y && lr.y >= other.ul.y) return true;
	return false;
}
