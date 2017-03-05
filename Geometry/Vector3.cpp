#include "Vector3.h"

void Vector3::init()
{
	values = new float[3];
}

Vector3::Vector3()
{
	init();

	setX(0);
	setY(0);
	setZ(0);
}

Vector3::Vector3(const Vector3 & vector)
{
	init();

	setX(vector.getX());
	setY(vector.getY());
	setZ(vector.getZ());
}

Vector3::Vector3(float x, float y, float z)
{
	init();

	setX(x);
	setY(y);
	setZ(z);
}

Vector3::~Vector3()
{
	delete[] values;
}

inline float Vector3::getX() const
{
	return values[0];
}

inline float Vector3::getY() const
{
	return values[1];
}

inline float Vector3::getZ() const
{
	return values[2];
}

inline float Vector3::getValue(int i) const
{
	return values[i];
}

inline void Vector3::setX(const float & x)
{
	setValue(0, x);
}

inline void Vector3::setY(const float & y)
{
	setValue(1, y);
}

inline void Vector3::setZ(const float & z)
{
	setValue(2, z);
}

inline void Vector3::setValue(int i, const float & value)
{
	if (isinf(value) || isnan(value))
		throw INVALID_VALUE_EXCEPTION;	// Invalid value.

	values[i] = value;
}

Vector3 Vector3::normalize()
{
	if (getX() == 0 && getY() == 0 && getZ() == 0)
		throw NORMALIZE_IMPOSSIBLE;	// Vector(0,0,0) can't be normalize, result not clear.

	float factor = 1 / getAbs();

	setX(getX() * factor);
	setY(getY() * factor);
	setZ(getZ() * factor);

	return *this;
}

Vector3 Vector3::getNormalized() const
{
	Vector3 result = Vector3(*this);

	result.normalize();

	return result;
}

inline float Vector3::getAbs() const
{
	return sqrtf(getX() * getX() + getY() * getY() + getZ() * getZ());	// Pythagoras.
}

Vector3 Vector3::rotate(const float & angleX, const float & angleY, const float & angleZ)
{
	if (isinf(angleX) || isnan(angleX) || isinf(angleY) || isnan(angleY) || isinf(angleZ) || isnan(angleZ))
		throw INVALID_VALUE_EXCEPTION;	// Invalid value.

	Matrix3 x = Matrix3::getRotationX(angleX);
	Matrix3 y = Matrix3::getRotationY(angleY);
	Matrix3 z = Matrix3::getRotationZ(angleZ);

	*this *= x * y * z;

	return *this;
}

Vector3 Vector3::getRotated(const float & angleX, const float & angleY, const float & angleZ)
{
	Vector3 result = Vector3(*this);

	result.rotate(angleX, angleY, angleZ);

	return result;
}

Vector3 Vector3::ONE()
{
	return Vector3(1, 1, 1);
}

Vector3 Vector3::ZERO()
{
	return Vector3(0, 0, 0);
}

Vector3 Vector3::UP()
{
	return Vector3(0, 0, 1);
}

Vector3 Vector3::DOWN()
{
	return Vector3(0, 0, -1);
}

Vector3 Vector3::LEFT()
{
	return Vector3(-1, 0, 0);
}

Vector3 Vector3::RIGHT()
{
	return Vector3(1, 0, 0);
}

Vector3 Vector3::BACK()
{
	return Vector3(0, -1, 0);
}

Vector3 Vector3::FORWARD()
{
	return Vector3(0, 1, 0);
}

Vector3 & Vector3::operator+=(Vector3 const & rhs)
{
	setX(getX() + rhs.getX());
	setY(getY() + rhs.getY());
	setZ(getZ() + rhs.getZ());

	return *this;
}

Vector3 & Vector3::operator*=(Matrix3 const & rhs)
{
	for (int n = 0; n < 3; n++)
	{
		float value = 0;

		for (int m = 0; m < 3; m++)
			value += getValue(n) * rhs.getValue(m, n);

		setValue(n, value);
	}

	return *this;
}

Vector3 & Vector3::operator*=(float const & rhs)
{
	setX(getX() * rhs);
	setY(getY() * rhs);
	setZ(getZ() * rhs);

	return Vector3(*this);
}

const Vector3 operator+(Vector3 const & lhs, Vector3 const & rhs)
{
	Vector3 result = Vector3(lhs);

	result += rhs;

	return Vector3(result);
}

const float operator*(Vector3 const & lhs, Vector3 const & rhs)
{
	float result = lhs.getX() * rhs.getX() + lhs.getY() * rhs.getY() + lhs.getZ() * rhs.getZ();

	return result;
}

const Vector3 operator*(Vector3 const & lhs, Matrix3 const & rhs)
{
	Vector3 result = Vector3(lhs);

	result *= rhs;

	return result;
}

const Vector3 operator*(Vector3 const & lhs, float const & rhs)
{
	Vector3 result = Vector3(lhs);

	result *= rhs;

	return result;
}
