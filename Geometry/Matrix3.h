#include <math.h>
#include "exceptions.h"

#pragma once
class Matrix3
{
private:
	float * data;
	void init();

public:
	Matrix3();
	Matrix3(const Matrix3 & matrix);
	Matrix3(float * m0, float * m1, float * m2);
	Matrix3(float m0n0, float m0n1, float m0n2, float m1n0, float m1n1, float m1n2, float m2n0, float m2n1, float m2n2);
	~Matrix3();

	inline float getValue(int m, int n) const;

	inline void setValue(int m, int n, const float & value);

	Matrix3 transpose();

	static Matrix3 UNIT();
	
	static Matrix3 getRotationX(const float & angle);
	static Matrix3 getRotationY(const float & angle);
	static Matrix3 getRotationZ(const float & angle);

	Matrix3 & operator+=(Matrix3 const & rhs);
	Matrix3 & operator*=(Matrix3 const & rhs);
};

const Matrix3 operator*(Matrix3 const & lhs, Matrix3 const & rhs);
const Matrix3 operator+(Matrix3 const & lhs, Matrix3 const & rhs);
