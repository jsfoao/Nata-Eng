#pragma once
#include "Editor.h"
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "Render/RenderBuffer.h"
#include "Vector/Vector2.h"
#include "Color/Color.h"
#include "Window/Window.h"
#include "Input/Input.h"
#include "Debug/Debug.h"

#include "ECS/ECS.h"
#include "Components/Core/Transform.h"
#include "Components/Core/Renderer.h"
#include "Components/Core/Collider.h"
#include "Components/Core/Rigidbody.h"

#include "Entities/Core/CoreEntities.h"

class Engine
{
public:
	bool isRunning;
	Window* window;
	SDL_Renderer* renderer;
	std::vector<Entity*> entities;
	std::vector<Collider*> colliders;
	static float deltaTime;

public:
	Engine();
	~Engine();

	void init(const char* title, int x, int y, int width, int height, bool fullscreen);

	void handleEvents();
	void start();
	void update();
	void render();
	void clean();

	void addEntity(Entity* entity)
	{
		entity->sdl_renderer = renderer;
		entities.push_back(entity);
	}

	void removeEntity(Entity* entity)
	{
		for (size_t i = 0; i < entities.size(); i++)
		{
			if (entities[i] == entity)
			{
				entities.erase(std::next(entities.begin(), i));
			}
		}
	}

	void resetScene()
	{
		for (size_t i = 0; i < entities.size(); i++)
		{
			for (size_t j = 0; j < entities[i]->components.size(); j++)
			{
				delete entities[i]->components[j];
			}
			removeEntity(entities[i]);
			delete entities[i];
		}
		entities.clear();
	}

	bool running() { return isRunning; }
};

#pragma region Global funcs
Entity* Instantiate(Entity* entity);
Entity* Instantiate(Entity* entity, Vector2 position);
Entity* Instantiate(Entity* entity, Vector2 position, Vector2 scale);
void Destroy(Entity* entity);
#pragma endregion

