#pragma once
#include "Vector3.h"

namespace Maths
{
#define PI  3.14159265358979323846 
#define Two_PI (2.0*PI)

	static float ToRadian(const float angleInDeg)
	{
		return angleInDeg*(PI/180.0);
	}

	static float ToDegrees(const float angleInRad)
	{
		return angleInRad*(180.0/PI);
	}

	typedef  Vector4 Color;

	static Color WHITE = Vector4(1, 1, 1,1.0);
	static Color BLACK = Vector4(0, 0, 0, 1.0);
	static Color GRAY =  Vector4(0.5, 0.5, 0.5, 1.0);
	static Color RED =  Vector4(1, 0, 0, 1.0);
	static Color GREEN= Vector4(0, 1, 0, 1.0);
	static Color BLUE = Vector4(0, 0, 1, 1.0);
}
