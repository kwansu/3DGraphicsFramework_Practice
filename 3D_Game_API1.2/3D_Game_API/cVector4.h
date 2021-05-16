#pragma once
#include "cVector3.h"

class cVector4 :
	public cVector3
{
public:
	float w;

public:
	cVector4();
	cVector4(cVector3 vec);
	cVector4(float _x, float _y, float _z, float _w);
	~cVector4();
	void Initialize();

	cVector4 operator+(cVector4& vec);
	cVector4 operator-(cVector4& vec);
	cVector4 operator*(float scalar);
	//cVector4 operator/(float scalar);
	operator POINT();
	float& operator()(int index); // 0 = x, 1 = y, 2 = z, 3 = w
};

