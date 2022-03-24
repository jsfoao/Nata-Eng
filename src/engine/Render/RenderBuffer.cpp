#include "RenderBuffer.h"
#include "../src/engine/Engine.h"

#define MAX_QUEUE 99

extern Engine* n_engine;

void RenderBuffer::Render()
{
	int queue_i = 0;
	while (queue_i < MAX_QUEUE)
	{
		for (int i = n_engine->entities.size() - 1; i >= 0; i--)
		{
			Renderer* renderer = n_engine->entities[i]->getComponent<Renderer>();
			if ((int)renderer->renderLayer == queue_i)
			{
				n_engine->entities[i]->render();
			}
		}
		queue_i++;
	}
}
