#include "PhysicsWorld.h"

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (Particle* particle : particles) {
		particle->Update(deltaTime);
	}
}
