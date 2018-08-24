#pragma once
class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float m_x, float m_y);
	//friend  Vector3 operator + (const Vector3& v1, const Vector3& v2);
	Vector2 operator + (const Vector2& vec);
	friend  Vector2 operator - (const Vector2& v1, const Vector2& v2);
	//Vector3 operator - (const Vector3& vec) const;
	friend  Vector2 operator * (const float scaler, const Vector2& vec3);
	Vector2 operator * (const float scaler);
	Vector2 operator / (const float scaler);
	friend  Vector2 operator / (const Vector2 & vec3, const float scaler);
	static  float CrossProduct(const Vector2& v1, const Vector2& v2);
	static  float DotProduct(const Vector2& v1, const Vector2& v2);
	static  float Distance(const Vector2& v1, const Vector2& v2);
	Vector2 Normalization();
	static  float Magnitude(const Vector2& vec2);
	static  float SqrMagnitude(const Vector2& vec2);
	float Magnitude() const;
	float SqrMagnitude() const;
};