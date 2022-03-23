#pragma once
#include "../src/engine/ECS/ECS.h"
#include "../src/engine/Components/Core/Collider.h"

class Collider_Circle : public Collider
{
public:
	float radius;
};

bool circle_intersect(Collider_Circle a, Collider_Circle b);