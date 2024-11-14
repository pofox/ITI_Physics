#include "Vector2d.h"

Vector2d::Vector2d()
{
	x = 0;
	y = 0;
}

Vector2d::Vector2d(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vector2d Vector2d::operator+(Vector2d other)
{
	return Vector2d(this->x + other.x, this->y + other.y);
}

Vector2d Vector2d::operator-(Vector2d other)
{
	return Vector2d(this->x - other.x, this->y - other.y);
}

Vector2d& Vector2d::operator+=(Vector2d other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2d& Vector2d::operator-=(Vector2d other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2d& Vector2d::operator=(Vector2d other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

bool Vector2d::operator==(Vector2d other)
{
	return (this->x == other.x) && (this->y == other.y);
}

Vector2d Vector2d::operator*(float a)
{
	return Vector2d(a * this->x, a * this->y);
}

Vector2d Vector2d::operator/(float a)
{
	return Vector2d(this->x / a, this->y / a);
}

Vector2d& Vector2d::operator*=(float a)
{
	this->x *= a;
	this->y *= a;
	return *this;
}

Vector2d& Vector2d::operator/=(float a)
{
	this->x /= a;
	this->y /= a;
	return *this;
}

float Vector2d::Dot(Vector2d other)
{
	return this->x * other.x + this->y * other.y;
}

float Vector2d::getMagnitude()
{
	return sqrt(Dot(*this));
}

Vector2d Vector2d::getNormalized()
{
	return *this /= this->getMagnitude();
}

void Vector2d::normalize()
{
	this->x /= this->getMagnitude();
	this->y /= this->getMagnitude();
}

Vector2d::operator Vector2f()
{
	return Vector2f(this->x, this->y);
}

Vector2d Vector2d::getNormal()
{
	return Vector2d(-this->y, this->x);
}

void Vector2d::print()
{
	printf("%fi+%fj\n", this->x, this->y);
}
