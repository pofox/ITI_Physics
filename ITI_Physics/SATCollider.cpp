#include "SATCollider.h"

void SATCollider::updatePosition(Vector2d position)
{
	Vector2d delta = position - this->position ;
	for (int i = 0; i < points.size(); i++)
	{
		points[i] += delta;
	}
	this->position = position;
}

bool SATCollider::checkCollision(SATCollider other)
{
	vector<Vector2d> normals = getNormals();
	for (int i = 0; i < normals.size(); i++)
	{
		Vector2d l1 = projectShape(normals[i]);
		Vector2d l2 = other.projectShape(normals[i]);
		if (l1.x > l2.y || l1.y < l2.x) return false;
	}
	normals = other.getNormals();
	for (int i = 0; i < normals.size(); i++)
	{
		Vector2d l1 = projectShape(normals[i]);
		Vector2d l2 = other.projectShape(normals[i]);
		if (l1.x > l2.y || l1.y < l2.x) return false;
	}
	return true;
}

vector<Vector2d> SATCollider::getNormals()
{
	vector<Vector2d> normals;
	for (int i = 1; i < points.size(); i++)
	{
		Vector2d dir = points[i - 1] - points[i];
		normals.push_back(dir.getNormal().getNormalized());
	}
	Vector2d dir = points[points.size() - 1] - points[0];
	normals.push_back(dir.getNormal().getNormalized());
	return normals;
}

Vector2d SATCollider::projectShape(Vector2d axis)
{
	float min, max;
	min = max = points[0].Dot(axis);
	for (int i = 1; i < points.size(); i++)
	{
		float newpoint = points[i].Dot(axis);
		if (newpoint < min) min = newpoint;
		if (newpoint > max) max = newpoint;
	}
	return Vector2d(min,max);
}
