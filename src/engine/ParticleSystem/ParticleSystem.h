#pragma once
#include "../src/engine/Engine.h"

struct ParticleProperties
{
	Vector2 Position;
	Vector2 Velocity, VelocityVariation;
	Color ColorBegin, ColorEnd;
	float SizeBegin, SizeEnd, SizeVariation;
	float LifeTime = 1.f;
};

class Particle
{
	Vector2 Position;
	Vector2 Velocity;
	Color ColorBegin, ColorEnd;
	float Roation = 0.f;
	float SizeBegin, SizeEnd;

	float LifeTime = 1.f;
	float LifeRemaining = 0.f;

	bool Active = false;
};

class ParticleSystem
{
public:
	ParticleSystem();

	void update();
	void render();

	void emit(const ParticleProperties& particleProperties);

private:
	std::vector<Particle> particlePool;

};