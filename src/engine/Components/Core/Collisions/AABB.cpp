#include "AABB.h"

bool aabb_intersect(const Collider_AABB a, const Collider_AABB b)
{
	if (abs(a.position.x - b.position.x) > (a.scale.x + b.scale.x))
		return false;
	if (abs(a.position.y - b.position.y) > (a.scale.y + b.scale.y))
		return false;
	return true;
}