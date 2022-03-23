#include "Circle.h"

bool circle_intersect(Collider_Circle a, Collider_Circle b)
{
	Vector2 diff = a.position - b.position;
	float dist2 = Vector2::Dot(diff, diff);
	float radiusSum = a.radius + b.radius;

	return dist2 <= radiusSum * radiusSum;
}