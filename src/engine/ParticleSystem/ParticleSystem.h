#pragma once
#include "../src/engine/Engine.h"

struct ParticleProperties
{
public:
	Vector2 Position;
	Vector2 Scale;
	Vector2 Velocity, VelocityVariation;
	Color Color = Color::White;
	float LifeTime = 1.f;
};

class Particle
{
public:
	Vector2 Position;
	Vector2 Scale;
	Vector2 Velocity;
	Color Color;

	float LifeTime = 1.f;
	float CurrentLifeTime = 0.f;

	bool Active = false;
};

class ParticleSystem : public Component
{
public:
	ParticleSystem();

	void update();
	void render();

	void emit(const ParticleProperties& particleProperties);

private:
	std::vector<Particle> particlePool;
	int poolIndex;
};