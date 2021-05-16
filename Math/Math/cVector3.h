#pragma once

class cVector3
{
public:
	float x, y, z;

	cVector3();
	cVector3(float _x, float _y, float _z);
	~cVector3();
	
	float Length();
	cVector3 Normalize();
	static float Dot(const cVector3& v1, const cVector3& v2);
	static cVector3 Cross(const cVector3& v1, const cVector3& v2);
	void Print();

	bool operator==(const cVector3& vec);
	bool operator!=(const cVector3& vec);
	cVector3 operator+(const cVector3& vec);
	cVector3 operator-(const cVector3& vec);
	cVector3 operator*(float scalar);
	cVector3 operator/(float scalar);
};


cVector3 operator*(float scalar, cVector3& vec);
cVector3 operator-(cVector3& vec);

