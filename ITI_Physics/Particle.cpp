#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->postion = postion;
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
}

void Particle::Update(float dt)
{
	Vector2d a = forces / mass;
	Vector2d v = a * dt;
	postion += v * dt;
	forces *= 0;
}

void Particle::addForce(Vector2d force)
{
	forces += force;
}
