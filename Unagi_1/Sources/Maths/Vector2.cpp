#include "..\..\Includes\Maths\Vector2.h"
#include <corecrt_math.h>
//#include "Maths/Vector3.h"
#include <cassert>

Vector2::Vector2() :
	x(0),
	y(0)
{}

Vector2::Vector2(float m_x, float m_y) :
	x(m_x),
	y(m_y)
{}

Vector2 Vector2::operator+(const Vector2 & vec)
{
	return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator*(const float scaler)
{
	return Vector2(scaler*x, scaler*y);
}

Vector2 Vector2::operator/(const float scaler)
{
	return Vector2(x/scaler, y/scaler);
}

float Vector2::CrossProduct(const Vector2 & v1, const Vector2 & v2)
{
	return v1.x*v2.y - v1.y*v2.x;
}

float Vector2::DotProduct(const Vector2 & v1, const Vector2 & v2)
{
	return v1.x*v2.x + v1.y*v2.y;;
}

float Vector2::Distance(const Vector2 & v1, const Vector2 & v2)
{
	return 0.0f;
}

Vector2 Vector2::Normalization()
{
	return Vector2();
}

float Vector2::Magnitude(const Vector2 & vec2)
{
	return sqrtf(SqrMagnitude(vec2));
}

float Vector2::SqrMagnitude(const Vector2 & vec2)
{
	return (vec2.x*vec2.x + vec2.y * vec2.y);
}

float Vector2::Magnitude() const
{
	return sqrtf(SqrMagnitude());
}

float Vector2::SqrMagnitude() const
{
	return (x*x + y * y);
}

Vector2 operator-(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

Vector2 operator*(const float scaler, const Vector2 & vec3)
{
	return Vector2(scaler*vec3.x, scaler*vec3.y);
}

Vector2 operator/(const Vector2 & vec3, const float scaler)
{
	assert(scaler != 0 && "cant divide with zero");
	return Vector2(vec3.x / scaler, vec3.y / scaler);
}
