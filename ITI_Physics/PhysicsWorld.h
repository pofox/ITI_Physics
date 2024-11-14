#pragma once
#include "Particle.h"
#include <list>

using namespace std;

class PhysicsWorld
{
private:
	list<Particle*> particles;
public:
	void addParticle(Particle* particle);
	void Update(float deltaTime);

	static const Vector2d gravity;
};
