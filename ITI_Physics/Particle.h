#pragma once
#include "Vector2d.h"
#include "Collider.h"
#include "AABBCollider.h"
#include "SATCollider.h"

enum ColliderType
{
	Circle,
	AABB,
	SAT
};

class Particle
{
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d acceleration;
	Vector2d forces;
	Collider collider;
	AABBCollider aabbCollider;
	SATCollider satCollider;
	ColliderType type;

	float mass;
	float drag;

	Particle(Vector2d postion, float mass = 1, float drag = 0.3f);
	Particle(Vector2d postion, float radius, float mass = 1, float drag = 0.3f);
	Particle(Vector2d postion, Vector2d ul, Vector2d lr, float mass = 1, float drag = 0.3f);
	Particle(ConvexShape shape, float mass = 1, float drag = 0.3f);
	void Update(float dt);
	void addForce(Vector2d force);
};
