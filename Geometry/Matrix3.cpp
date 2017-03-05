#include "Matrix3.h"

void Matrix3::init()
{
	data = new float[9];
}

Matrix3::Matrix3()
{
	init();
}

Matrix3::Matrix3(const Matrix3 & matrix)
{
	init();

	setValue(0, 0, matrix.getValue(0, 0));
	setValue(0, 1, matrix.getValue(0, 1));
	setValue(0, 2, matrix.getValue(0, 2));
	setValue(1, 0, matrix.getValue(1, 0));
	setValue(1, 1, matrix.getValue(1, 1));
	setValue(1, 2, matrix.getValue(1, 2));
	setValue(2, 0, matrix.getValue(2, 0));
	setValue(2, 1, matrix.getValue(2, 1));
	setValue(2, 2, matrix.getValue(2, 2));
}

Matrix3::Matrix3(float * m0, float * m1, float * m2)
{
	init();

	setValue(0, 0, m0[0]);
	setValue(0, 1, m0[1]);
	setValue(0, 2, m0[2]);
	setValue(1, 0, m1[0]);
	setValue(1, 1, m1[1]);
	setValue(1, 2, m1[2]);
	setValue(2, 0, m2[0]);
	setValue(2, 1, m2[1]);
	setValue(2, 2, m2[2]);
}

Matrix3::Matrix3(float m0n0, float m0n1, float m0n2, float m1n0, float m1n1, float m1n2, float m2n0, float m2n1, float m2n2)
{
	init();

	setValue(0, 0, m0n0);
	setValue(0, 1, m0n1);
	setValue(0, 2, m0n2);
	setValue(1, 0, m1n0);
	setValue(1, 1, m1n1);
	setValue(1, 2, m1n2);
	setValue(2, 0, m2n0);
	setValue(2, 1, m2n1);
	setValue(2, 2, m2n2);
}

Matrix3::~Matrix3()
{
	delete[] data;
}

float Matrix3::getValue(int m, int n) const
{
	return data[m * 3 + n];
}

void Matrix3::setValue(int m, int n, const float & value)
{
	if (isinf(value) || isnan(value))
		throw INVALID_VALUE_EXCEPTION;	// Invalid value.

	data[m * 3 + n] = value;
}

Matrix3 Matrix3::transpose()
{
	return Matrix3(
		getValue(0, 0), getValue(1, 0), getValue(2, 0),
		getValue(0, 1), getValue(1, 1), getValue(2, 1),
		getValue(0, 2), getValue(1, 2), getValue(2, 2));
}

Matrix3 Matrix3::UNIT()
{
	return Matrix3(1, 0, 0, 0, 1, 0, 0, 0, 1);
}

Matrix3 Matrix3::getRotationX(const float & angle)
{
	return Matrix3(
		1, 0, 0,
		0, cosf(angle), -sinf(angle),
		0, sinf(angle), cosf(angle));
}

Matrix3 Matrix3::getRotationY(const float & angle)
{
	return Matrix3(
		cosf(angle), 0, sinf(angle),
		0, 1, 0,
		-sinf(angle), 0, cosf(angle));
}

Matrix3 Matrix3::getRotationZ(const float & angle)
{
	return Matrix3(
		cosf(angle), -sinf(angle), 0,
		sinf(angle), cosf(angle), 0,
		0, 0, 1);
}

Matrix3 & Matrix3::operator+=(Matrix3 const & rhs)
{
	setValue(0, 0, getValue(0, 0) + rhs.getValue(0, 0));
	setValue(0, 1, getValue(0, 1) + rhs.getValue(0, 1));
	setValue(0, 2, getValue(0, 2) + rhs.getValue(0, 2));
	setValue(1, 0, getValue(1, 0) + rhs.getValue(1, 0));
	setValue(1, 1, getValue(1, 1) + rhs.getValue(1, 1));
	setValue(1, 2, getValue(1, 2) + rhs.getValue(1, 2));
	setValue(2, 0, getValue(2, 0) + rhs.getValue(2, 0));
	setValue(2, 1, getValue(2, 1) + rhs.getValue(2, 1));
	setValue(2, 2, getValue(2, 2) + rhs.getValue(2, 2));

	return *this;
}

Matrix3 & Matrix3::operator*=(Matrix3 const & rhs)
{
	Matrix3 lhs = Matrix3(*this);

	for (int m = 0; m < 3; m++)
		for (int n = 0; n < 3; n++)
		{
			float value = 0;

			for (int i = 0; i < 3; i++)
				value += lhs.getValue(m, i) * rhs.getValue(i, n);

			setValue(m, n, value);
		}
	
	return *this;
}

const Matrix3 operator+(Matrix3 const & lhs, Matrix3 const & rhs)
{
	Matrix3 result = Matrix3(lhs);
	result += rhs;
	return result;
}

const Matrix3 operator*(Matrix3 const & lhs, Matrix3 const & rhs)
{
	Matrix3 result = Matrix3(lhs);
	result *= rhs;
	return result;
}
