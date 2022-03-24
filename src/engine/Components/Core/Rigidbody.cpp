#include "Rigidbody.h"

void Rigidbody::update()
{
	Component::update();
	owner->transform->position += velocity * Engine::deltaTime;
}