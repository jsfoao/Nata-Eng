#include "Debug.h"

extern Engine* n_engine;
void Debug::Log(std::string str)
{
	std::cout << str << std::endl;
}

void Debug::DrawLine(Vector2 a, Vector2 b)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(n_engine->renderer, a.x, b.x, a.y, b.y);
}

void Debug::DrawLine(Vector2 a, Vector2 b, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(n_engine->renderer, a.x, b.x, a.y, b.y);
}