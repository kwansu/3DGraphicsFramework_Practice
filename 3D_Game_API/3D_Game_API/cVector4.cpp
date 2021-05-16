#include "stdafx.h"
#include "cVector4.h"


cVector4::cVector4()
	: cVector3(), w(0)
{
}


cVector4::cVector4(cVector3 vec)
	: cVector3(vec), w(0)
{
}


cVector4::cVector4(float _x, float _y, float _z, float _w)
	: cVector3(_x, _y, _z), w(_w)
{
}


cVector4::~cVector4()
{
}


void cVector4::Initialize()
{
	if (!w || EqualFloat(w, 1))
		return;

	x /= w;
	y /= w;
	z /= w;
	w = 1;
}


cVector4 cVector4::operator+(cVector4& vec)
{
	Initialize();
	vec.Initialize();
	return cVector4(x + vec.x, y + vec.y, z + vec.z, !(w + vec.w) ? 1 : 0);
}


cVector4 cVector4::operator-(cVector4& vec)
{
	Initialize();
	vec.Initialize();
	return cVector4(x - vec.x, y - vec.y, z - vec.z, !(w - vec.w) ? 1 : 0);
}


float& cVector4::operator()(int index)
{
	switch (index)
	{
	case 0 :
		return x;
	case 1:
		return y;
	case 2:
		return z;
	case 3:
		return w;
	}
}


cVector4 cVector4::operator*(float scalar)
{
	Initialize();
	return cVector4(x*scalar, y*scalar, z*scalar, w);
}


cVector4 cVector4::operator/(float scalar)
{
	return this->operator/(scalar);
}
