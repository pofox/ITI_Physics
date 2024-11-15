#include "PhysicsWorld.h"

const Vector2d PhysicsWorld::gravity = Vector2d(0, 980);

void PhysicsWorld::addParticle(Particle* particle)
{
	particles.push_back(particle);
}

void PhysicsWorld::Update(float deltaTime)
{
	for (int i = 0; i < particles.size(); i++) {
		for (int j = i+1;j<particles.size();j++)
		{
			if (particles[i]->type == Circle && particles[j]->type == Circle)
			{
				if (particles[i]->collider.checkCollision(particles[j]->collider))
				{
					cout << "collision\n";
				}
			}
			else if (particles[i]->type == AABB && particles[j]->type == AABB)
			{
				if (particles[i]->aabbCollider.checkCollision(particles[j]->aabbCollider))
				{
					cout << "collision\n";
				}
			}
			else if ((particles[i]->type == SAT && particles[j]->type != Circle) || (particles[i]->type != Circle && particles[j]->type == SAT))
			{
				if (particles[i]->satCollider.checkCollision(particles[j]->satCollider))
				{
					cout << "collision\n";
				}
			}
			else {

			}
		}
		//particle->addForce(particle->mass * gravity);
		particles[i]->Update(deltaTime);
	}
}
