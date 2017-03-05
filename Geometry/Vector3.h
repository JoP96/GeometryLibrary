#include <math.h>
#include "Matrix3.h"
#include "exceptions.h"

#pragma once
class Vector3
{
private:
	float * values;
	void init();

public:
	Vector3();
	Vector3(const Vector3 & vector);
	Vector3(float x, float y, float z);
	~Vector3();

	inline float getX() const;
	inline float getY() const;
	inline float getZ() const;
	inline float getValue(int i) const;

	inline void setX(const float & x);
	inline void setY(const float & y);
	inline void setZ(const float & z);
	inline void setValue(int i, const float & value);

	Vector3 normalize();
	Vector3 getNormalized() const;

	inline float getAbs() const;

	Vector3 rotate(const float & angleX, const float & angleY, const float & angleZ);
	Vector3 getRotated(const float & angleX, const float & angleY, const float & angleZ);

	static Vector3 ONE();
	static Vector3 ZERO();
	static Vector3 UP();
	static Vector3 DOWN();
	static Vector3 LEFT();
	static Vector3 RIGHT();
	static Vector3 BACK();
	static Vector3 FORWARD();

	Vector3 & operator+=(Vector3 const & rhs);
	Vector3 & operator*=(Matrix3 const & rhs);
	Vector3 & operator*=(float const & rhs);
};

const Vector3 operator+(Vector3 const & lhs, Vector3 const & rhs);
const float operator*(Vector3 const & lhs, Vector3 const & rhs);
const Vector3 operator*(Vector3 const & lhs, Matrix3 const & rhs);
const Vector3 operator*(Vector3 const & lhs, float const & rhs);