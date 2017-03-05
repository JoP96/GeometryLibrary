#include "main.h"

int main()
{
	std::cout << "For testing..." << std::endl;

	std::cin.get();
	return 0;
}

void printVector(const Vector3 & v)
{
	float x = v.getX();
	float y = v.getY();
	float z = v.getZ();

	std::cout
		<< x << std::endl
		<< y << std::endl
		<< z << std::endl
		<< std::endl;
}

void printMatrix(const Matrix3 & m)
{
	float f00 = m.getValue(0, 0);
	float f01 = m.getValue(0, 1);
	float f02 = m.getValue(0, 2);
	float f10 = m.getValue(1, 0);
	float f11 = m.getValue(1, 1);
	float f12 = m.getValue(1, 2);
	float f20 = m.getValue(2, 0);
	float f21 = m.getValue(2, 1);
	float f22 = m.getValue(2, 2);

	std::cout
		<< f00 << ' ' << f01 << ' ' << f02 << ' ' << std::endl
		<< f10 << ' ' << f11 << ' ' << f12 << ' ' << std::endl
		<< f20 << ' ' << f21 << ' ' << f22 << ' ' << std::endl
		<< std::endl;
}
