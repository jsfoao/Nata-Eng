#pragma once
#include "../src/engine/ECS/ECS.h"
#include "../src/engine/Components/Core/Collider.h"

class Collider_AABB : public Collider
{
public:
	Vector2 scale;
};

bool aabb_intersect(Collider_AABB a, Collider_AABB b);