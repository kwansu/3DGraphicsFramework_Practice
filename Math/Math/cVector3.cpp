#include "StdAfx.h"
#include "cVector3.h"


cVector3::cVector3(void)
{
}


cVector3::cVector3(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z)
{
}


cVector3::~cVector3(void)
{
}


bool cVector3::operator==(const cVector3& vec)
{
	if (!IsInEpsilon(x, vec.x))
		return false;
	if (!IsInEpsilon(y, vec.y))
		return false;
	if (!IsInEpsilon(z, vec.z))
		return false;

	return true;
}


bool cVector3::operator!=(const cVector3& vec)
{
	return !this->operator==(vec);
}


cVector3 cVector3::operator+(const cVector3& vec)
{
	cVector3 resultV;

	resultV.x = x + vec.x;
	resultV.y = y + vec.y;
	resultV.z = z + vec.z;
	return resultV;
}


cVector3 cVector3::operator-(const cVector3& vec)
{
	cVector3 resultV;

	resultV.x = x - vec.x;
	resultV.y = y - vec.y;
	resultV.z = z - vec.z;
	return resultV;
}


cVector3 cVector3::operator*(float scalar)
{
	cVector3 resultV;

	resultV.x = x * scalar;
	resultV.y = y * scalar;
	resultV.z = z * scalar;
	return resultV;
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
	cVector3 resultV;

	resultV.x = v1.y*v2.z - v1.z*v2.y;
	resultV.y = v1.z*v2.x - v1.x*v2.z;
	resultV.z = v1.x*v2.y - v1.y*v2.x;
	return resultV;
}


void cVector3::Print()
{
	cout << endl;

	cout << "( " << x << "\t, " << y << "\t, " << z << " )\t length = " << Length() << endl;
}


cVector3 operator*(float scalar, cVector3& vec)
{
	return vec.operator*(scalar);
}


cVector3 operator-(cVector3& vec)
{
	return vec.operator*(-1);
}
