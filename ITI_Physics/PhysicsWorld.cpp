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
					HandelCollision(particles[i], particles[j]);
				}
			}
			else if (particles[i]->type == AABB && particles[j]->type == AABB)
			{
				if (particles[i]->aabbCollider.checkCollision(particles[j]->aabbCollider))
				{
					HandelCollision(particles[i], particles[j]);
				}
			}
			else if ((particles[i]->type == SAT && particles[j]->type != Circle) || (particles[i]->type != Circle && particles[j]->type == SAT))
			{
				if (particles[i]->satCollider.checkCollision(particles[j]->satCollider))
				{
					HandelCollision(particles[i], particles[j]);
				}
			}
			else {

			}
		}
		//particle->addForce(particle->mass * gravity);
		particles[i]->Update(deltaTime);
	}
}

void PhysicsWorld::HandelCollision(Particle* p1, Particle* p2)
{
	Vector2d v1 = p1->velocity;
	float m1 = p1->mass;
	Vector2d x1 = p1->position;

	Vector2d v2 = p2->velocity;
	float m2 = p2->mass;
	Vector2d x2 = p2->position;

	Vector2d normal1 = x1 - x2;

	float dot1 = (v1 - v2).Dot(normal1);

	float normalMag = normal1.getMagnitude();

	dot1 /= normalMag;
	dot1 /= normalMag;

	Vector2d normal2 = x2 - x1;

	float dot2 = (v2 - v1).Dot(normal2);

	normalMag = normal2.getMagnitude();

	dot2 /= normalMag;
	dot2 /= normalMag;

	v1 = v1 - (dot1 * ((2 * m2) / (m1 + m2))) * normal1;
	v2 = v2 - (dot2 * ((2 * m1) / (m1 + m2))) * normal2;

	p1->velocity = v1;
	p2->velocity = v2;
	//cout << "x=" << v1.x << "y=" << v1.y << "\n";
}
