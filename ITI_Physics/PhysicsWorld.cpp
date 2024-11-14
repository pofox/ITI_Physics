#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity = Vector2d(0, 980);

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (Particle* particle : particles) {
		particle->addForce(particle->mass * gravity);
		particle->Update(deltaTime);
	}
}
