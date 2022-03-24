#include "Debug.h"

#define TAU 6.28

extern Engine* n_engine;

static void draw_circle(Vector2 pos, float radius, int resolution, Color color);

void Debug::Log(std::string str)
{
	std::cout << str << std::endl;
}

void Debug::Log(float f)
{
	std::cout << f << std::endl;
}

void Debug::DrawLine(Vector2 a, Vector2 b)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(n_engine->renderer, a.x, a.y, b.x, b.y);
}

void Debug::DrawLine(Vector2 a, Vector2 b, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(n_engine->renderer, a.x, a.y, b.x, b.y);
}

void Debug::DrawRay(Vector2 point, Vector2 direction)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(n_engine->renderer, point.x, point.y, point.x + direction.x, point.y + direction.y);
}

void Debug::DrawRay(Vector2 point, Vector2 direction, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(n_engine->renderer, point.x, point.y, point.x + direction.x, point.y + direction.y);
}

void Debug::DrawSquareWire(Vector2 pos, Vector2 scale)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	SDL_Rect rect =
	{
		pos.x - scale.x / 2,
		pos.y - scale.y / 2,
		scale.x,
		scale.y
	};
	SDL_RenderDrawRect(n_engine->renderer, &rect);
}

void Debug::DrawSquareWire(Vector2 pos, Vector2 scale, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect =
	{
		pos.x - scale.x / 2,
		pos.y - scale.y / 2,
		scale.x,
		scale.y
	};
	SDL_RenderDrawRect(n_engine->renderer, &rect);
}

void Debug::DrawSquareFill(Vector2 pos, Vector2 scale)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	SDL_Rect rect =
	{
		pos.x - scale.x / 2,
		pos.y - scale.y / 2,
		scale.x,
		scale.y
	};
	SDL_RenderFillRect(n_engine->renderer, &rect);
}

void Debug::DrawSquareFill(Vector2 pos, Vector2 scale, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect =
	{
		pos.x - scale.x / 2,
		pos.y - scale.y / 2,
		scale.x,
		scale.y
	};
	SDL_RenderFillRect(n_engine->renderer, &rect);
}

void Debug::DrawCircleWire(Vector2 pos, float radius, int resolution)
{
	SDL_SetRenderDrawColor(n_engine->renderer, 255, 255, 255, 255);
	draw_circle(pos, radius, resolution, Color::White);
}

void Debug::DrawCircleWire(Vector2 pos, float radius, int resolution, Color color)
{
	draw_circle(pos, radius, resolution, color);
}

#pragma region Local funcs
static void draw_circle(Vector2 pos, float radius, int resolution, Color color)
{
	SDL_SetRenderDrawColor(n_engine->renderer, color.r, color.g, color.b, color.a);

	Vector2 p1;
	Vector2 p2;
	for (size_t i = 0; i < resolution; i++)
	{
		float angle1 = i * (TAU / resolution);
		float angle2 = (i + 1) * (TAU / resolution);

		p1 = pos + (Vector2(cos(angle1), sin(angle1)) * radius);
		p2 = pos + (Vector2(cos(angle2), sin(angle2)) * radius);
		SDL_RenderDrawLine(n_engine->renderer, p1.x, p1.y, p2.x, p2.y);
	}
}
#pragma endregion