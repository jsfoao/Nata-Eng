#pragma once
#include "../src/engine/Engine.h"

class PlayerController : public Component
{
public:
	float speed;
	ParticleProperties pp;
public:
	void start() override
	{
		speed = 200.f;
	}
	void update() override
	{
		if (Input::GetKeyDown(SDL_SCANCODE_SPACE))
		{
			owner->getComponent<ParticleSystem>()->emit(pp);
		}

		// Movement controls
		if (Input::GetKey(SDL_SCANCODE_W))
		{
			owner->transform->position.y -= speed * Engine::deltaTime;
		}
		if (Input::GetKey(SDL_SCANCODE_S))
		{
			owner->transform->position.y += speed * Engine::deltaTime;
		}
		if (Input::GetKey(SDL_SCANCODE_A))
		{
			owner->transform->position.x -= speed * Engine::deltaTime;
		}
		if (Input::GetKey(SDL_SCANCODE_D))
		{
			owner->transform->position.x += speed * Engine::deltaTime;
		}
	}
};