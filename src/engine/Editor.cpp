#include "Editor.h"
#pragma region Components
#include "../src/game/Scripts/Components/PlayerController.hpp"
#pragma endregion

static Entity* entity1 = nullptr;
static Entity* entity2 = nullptr;
void Editor::execute_start()
{
	entity1 = Instantiate(new Entity(), Vector2(100, 100));
	entity1->addComponent<Renderer>();
	entity1->addComponent<PlayerController>();
	entity1->getComponent<Renderer>()->color = Color::Red;
	entity1->transform->scale = Vector2(32, 32);

	entity2 = Instantiate(new Entity(), Vector2(200, 200));
	entity2->addComponent<Renderer>();
	entity2->getComponent<Renderer>()->color = Color::Green;
	entity2->getComponent<Renderer>()->renderLayer = RenderLayer::Foreground;
	entity2->transform->scale = Vector2(32, 32);
}

void Editor::execute_update()
{
}