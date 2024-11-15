#pragma once
#include "Particle.h"
#include <vector>

using namespace std;

class PhysicsWorld
{
private:
	vector<Particle*> particles;
public:
	void addParticle(Particle* particle);
	void Update(float deltaTime);

	static const Vector2d gravity;
};
