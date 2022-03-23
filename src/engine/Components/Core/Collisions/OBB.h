#pragma once
#include "../src/engine/ECS/ECS.h"
#include "../src/engine/Components/Core/Collider.h"

class Collider_OBB : public Collider
{
public:
	Vector2 u; // local x and y axes
	Vector2 e; // local scale
};

bool intersect_obb(Collider_OBB a, Collider_OBB b);