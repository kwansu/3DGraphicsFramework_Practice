#include "StdAfx.h"
#include "cVector3.h"


cVector3::cVector3()
	: x(0), y(0), z(0)
{
}


cVector3::cVector3(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z)
{
}


cVector3::~cVector3()
{
}


bool cVector3::operator==(const cVector3& vec)
{
	if (!EqualFloat(x, vec.x))
		return false;
	if (!EqualFloat(y, vec.y))
		return false;
	if (!EqualFloat(z, vec.z))
		return false;

	return true;
}


bool cVector3::operator!=(const cVector3& vec)
{
	return !this->operator==(vec);
}


cVector3 cVector3::operator+(const cVector3& vec)
{
	return cVector3(x + vec.x, y + vec.y, z + vec.z);
}


cVector3 cVector3::operator-(const cVector3& vec)
{
	return cVector3(x - vec.x, y - vec.y, z - vec.z);
}


cVector3 cVector3::operator*(float scalar)
{
	return cVector3(x*scalar, y*scalar, z*scalar);

}


cVector3 cVector3::operator/(float scalar)
{
	return this->operator*(1 / scalar);
}


float cVector3::Length()
{
	return sqrt(x*x + y*y + z*z);
}


cVector3 cVector3::Normalize()
{
	return this->operator/(Length());
}


float cVector3::Dot(const cVector3& v1, const cVector3& v2)
{
	return (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
}


cVector3 cVector3::Cross(const cVector3& v1, const cVector3& v2)
{
	return cVector3(v1.y*v2.z - v1.z*v2.y
		, v1.z*v2.x - v1.x*v2.z
		, v1.x*v2.y - v1.y*v2.x);
}


cVector3 operator*(float scalar, cVector3& vec)
{
	return vec.operator*(scalar);
}


cVector3 operator-(cVector3& vec)
{
	return vec.operator*(-1);
}
