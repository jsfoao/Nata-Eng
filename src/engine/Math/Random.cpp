#include "Random.h"

float Random::Range()
{
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	return r;
}

float Random::Range(float min, float max)
{
	float r = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	return r;
}