#include "ParticleSystem.h"
#include "../src/engine/Math/Random.h"

#define TAU 6.28

ParticleSystem::ParticleSystem()
{
	particlePool.resize(1000);
}

void ParticleSystem::update()
{
	for (auto& particle : particlePool)
	{
		if (!particle.Active)
		{
			continue;
		}

		if (particle.CurrentLifeTime <= 0.f)
		{
			particle.Active = false;
			continue;
		}

		particle.CurrentLifeTime -= Engine::deltaTime;
		particle.Position += particle.Velocity * Engine::deltaTime;
	}
}

void ParticleSystem::render()
{
	for (auto& particle : particlePool)
	{
		if (!particle.Active)
		{
			continue;
		}
	}
}

void ParticleSystem::emit(const ParticleProperties& pp)
{
	Particle& particle = particlePool[poolIndex];
	particle.Active = true;

	// Position and Scale
	particle.Position = pp.Position;
	particle.Scale = pp.Scale * Random::Range(0.5f, 1.f);

	// Velocity
	particle.Velocity = pp.Velocity;
	particle.Velocity.x += pp.VelocityVariation.x * Random::Range(-1.f, 1.f);
	particle.Velocity.y += pp.VelocityVariation.y * Random::Range(-1.f, 1.f);

	// Color
	particle.Color = pp.Color;

	// LifeTime
	particle.LifeTime = pp.LifeTime;
	particle.CurrentLifeTime = pp.LifeTime;

	poolIndex = --poolIndex % particlePool.size();
}