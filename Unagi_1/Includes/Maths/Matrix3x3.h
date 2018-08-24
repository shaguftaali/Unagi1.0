#pragma once
#include "Vector3.h"

class Matrix3x3
{
public:
	Matrix3x3();
	Matrix3x3(const float arg[3][3]);
	Matrix3x3(const Vector3& v1, const Vector3& v2, const Vector3& v3);

	Matrix3x3 Transpose();

	friend Matrix3x3 operator +(const Matrix3x3& mat1, const Matrix3x3& mat2);
	friend Matrix3x3 operator -(const Matrix3x3& mat1, const Matrix3x3& mat2);
	friend Matrix3x3 operator *(const Matrix3x3& mat1, const Matrix3x3& mat2);
	friend Matrix3x3 operator *(const Matrix3x3& mat1, const Matrix3x3& vector4);
	friend Matrix3x3 operator *(const float scaler, const Matrix3x3& mat2);
	friend Matrix3x3 operator /(const float scaler, const Matrix3x3& mat2);
	float* operator [](int index);
	const float* operator[](int index) const;
	static  const Matrix3x3 IdentityMat;
	Matrix3x3 Inverse() const;
protected:
	

private:
	float arr[3][3];
};
