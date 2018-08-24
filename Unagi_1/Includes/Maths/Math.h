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

	typedef  Vector3 Color;

	static Color WHITE = Vector3(1, 1, 1);
	static Color BLACK = Vector3(0, 0, 0);
	static Color GRAY =  Vector3(0.5, 0.5, 0.5);
	static Color RED =  Vector3(1, 0, 0);
	static Color GREEAN= Vector3(0, 1, 0);
	static Color BLUE = Vector3(0, 0, 1);
}
