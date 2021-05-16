#pragma once
#include "cMatrix.h"

class cMatrix4 :
	public cMatrix
{
public:
	cMatrix4();
	cMatrix4(cMatrix matrix);
	cMatrix4(cMatrix4& copy);
	~cMatrix4();

	static cMatrix4 Translate(float dx, float dy, float dz);
	static cMatrix4 Translate(cVector3 vec);
	static cMatrix4 RotateX(float fAngle);
	static cMatrix4 RotateY(float fAngle);
	static cMatrix4 RotateZ(float fAngle);
	static cMatrix4 Magnify(float fRatio);
	static cMatrix4 View(cVector4* pPosView, cVector4* pPosAt, cVector3* pVecUp);
	static cMatrix4 View(cVector4* pPosView, cVector3* pVecLook, cVector3* pVecUp, cVector3* pVecRight);
	static cMatrix4 Projection(float fFovY, float fAspect, float fNear, float fFar);
	static cMatrix4 Viewport(float fWidth, float fHeight);

	cVector4 operator*(cVector4& vec) const;
	cMatrix4 operator+(const cMatrix4& matrix);
	cMatrix4 operator-(const cMatrix4& matrix);
	cMatrix4 operator*(const cMatrix4& matrix);
	cMatrix4 operator*(float scalar);
	cMatrix4 operator/(float scalar);
	cMatrix4 operator=(const cMatrix4& matrix);
};
