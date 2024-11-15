#include "Particle.h"

Particle::Particle(Vector2d postion, float mass, float drag)
{
	this->position = postion;
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
}

Particle::Particle(Vector2d postion, float radius, float mass, float drag)
{
	this->position = postion;
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
	collider.center = postion;
	collider.r = radius;
	type = Circle;
}

Particle::Particle(Vector2d postion, Vector2d ul, Vector2d lr, float mass, float drag)
{
	this->position = postion;
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
	aabbCollider.position = postion;
	aabbCollider.ul = ul;
	aabbCollider.lr = lr;
	type = AABB;
}

Particle::Particle(ConvexShape shape, float mass, float drag)
{
	this->position = Vector2d(shape.getPosition().x,shape.getPosition().y);
	this->mass = mass;
	this->drag = drag;
	this->forces = Vector2d(0, 0);
	for (int i = 0; i < shape.getPointCount(); i++)
	{
		satCollider.points.push_back(Vector2d(shape.getPoint(i).x,shape.getPoint(i).y));
	}
	satCollider.updatePosition(position);
	type = SAT;
}

void Particle::Update(float dt)
{
	acceleration = forces / mass;
	velocity += acceleration * dt;
	position += velocity * dt;
	forces *= 0;

	//update collider
	switch (type)
	{
	case Circle:
		collider.center = position;
		break;
	case AABB:
		aabbCollider.updatePosition(position);
		break;
	case SAT:
		satCollider.updatePosition(position);
		break;
	default:
		break;
	}

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
