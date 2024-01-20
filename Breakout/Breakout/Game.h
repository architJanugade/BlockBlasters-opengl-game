#pragma once

#include <vector>
#include "game_level.h"
#include "ball_object.h"
#include <tuple>
enum GameState {
	GAME_ACTIVE,
	GAME_MENU,
	GAME_WIN
};
enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};
struct Particle {
	glm::vec2 Position, Velocity;
	glm::vec4 Color;
	float     Life;

	Particle()
		: Position(0.0f), Velocity(0.0f), Color(1.0f), Life(0.0f) { }
};
typedef std::tuple<bool, Direction, glm::vec2> Collision;
class Game {
public:
	GameState State;
	bool Keys[1024];
	bool isStarted;
	unsigned int Width, Height;
	Game(unsigned int width, unsigned int height);
	~Game();
	void Init();

	void ProcessInput(float dt);
	void Update(float dt);
	void Render();
	void ResetPlayer();
	void ResetLevel();
	std::vector<GameLevel> Levels;
	unsigned int           Level;
	void DoCollision();
	Direction VectorDirection(glm::vec2 target);
	Collision CheckCollision(BallObject &one, GameObject &two) // AABB - AABB collision
	{
		glm::vec2 center(one.Position + one.Radius);
		// calculate AABB info (center, half-extents)
		glm::vec2 aabb_half_extents(two.Size.x / 2.0f, two.Size.y / 2.0f);
		glm::vec2 aabb_center(
			two.Position.x + aabb_half_extents.x,
			two.Position.y + aabb_half_extents.y
		);
		// get difference vector between both centers
		glm::vec2 difference = center - aabb_center;
		glm::vec2 clamped = glm::clamp(difference, -aabb_half_extents, aabb_half_extents);
		// add clamped value to AABB_center and we get the value of box closest to circle
		glm::vec2 closest = aabb_center + clamped;
		// retrieve vector between center circle and closest point AABB and check if length <= radius
		difference = closest - center;
		if (glm::length(difference) <= one.Radius)
			return std::make_tuple(true, VectorDirection(difference), difference);
		else
			return std::make_tuple(false, UP, glm::vec2(0.0f, 0.0f));
	}

};