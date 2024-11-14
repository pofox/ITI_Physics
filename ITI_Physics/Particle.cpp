#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->position = postion;
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
}

void Particle::Update(float dt)
{
	acceleration = forces / mass;
	velocity += acceleration * dt;
	position += velocity * dt;
	forces *= 0;

	//drag
	if (velocity.getMagnitude() > 0.0f)
	{
		Vector2d dragForce = -0.5 * drag * velocity.getMagnitude() * velocity;
		addForce(dragForce);
	}
}

void Particle::addForce(Vector2d force)
{
	forces += force;
}
