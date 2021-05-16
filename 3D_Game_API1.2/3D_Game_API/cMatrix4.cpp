#include "stdafx.h"
#include "cMatrix4.h"


cMatrix4::cMatrix4()
	: cMatrix(4)
{
}


cMatrix4::cMatrix4(cMatrix matrix)
	: cMatrix(matrix)
{
}


cMatrix4::cMatrix4(cMatrix4& copy)
	: cMatrix(copy)
{
}


cMatrix4::~cMatrix4()
{
}


cMatrix4 cMatrix4::Translate(float dx, float dy, float dz)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	resultM.m_arr[3][0] = dx;
	resultM.m_arr[3][1] = dy;
	resultM.m_arr[3][2] = dz;
	return resultM;
}


cMatrix4 cMatrix4::Translate(cVector3 vec)
{
	return Translate(vec.x, vec.y, vec.z);
}



cMatrix4 cMatrix4::RotateX(float fAngle)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	fAngle *= RADIAN ;

	resultM.m_arr[1][1] = cos(fAngle);
	resultM.m_arr[1][2] = sin(fAngle);
	resultM.m_arr[2][1] = -sin(fAngle);
	resultM.m_arr[2][2] = cos(fAngle);
	return resultM;
}


cMatrix4 cMatrix4::RotateY(float fAngle)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	fAngle *= RADIAN;

	resultM.m_arr[0][0] = cos(fAngle);
	resultM.m_arr[0][2] = -sin(fAngle);
	resultM.m_arr[2][0] = sin(fAngle);
	resultM.m_arr[2][2] = cos(fAngle);
	return resultM;
}


cMatrix4 cMatrix4::RotateZ(float fAngle)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	fAngle *= RADIAN;

	resultM.m_arr[0][0] = cos(fAngle);
	resultM.m_arr[0][1] = sin(fAngle);
	resultM.m_arr[1][0] = -sin(fAngle);
	resultM.m_arr[1][1] = cos(fAngle);
	return resultM;
}


cMatrix4 cMatrix4::Magnify(float fRatio)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	resultM.m_arr[0][0] = fRatio;
	resultM.m_arr[1][1] = fRatio;
	resultM.m_arr[2][2] = fRatio;
	return resultM;
}


cMatrix4 cMatrix4::View(cVector4* pPosView, cVector4* pPosAt, cVector3* pVecUp)
{
	cMatrix4 resultM;

	cVector3 vecLook = (*pPosAt - *pPosView).Normalize();
	cVector3 vecRight = cVector3::Cross(*pVecUp, vecLook).Normalize();
	cVector3 vecUp = cVector3::Cross(vecLook, vecRight);

	resultM.m_arr[0][0] = vecRight.x;
	resultM.m_arr[1][0] = vecRight.y;
	resultM.m_arr[2][0] = vecRight.z;
	resultM.m_arr[3][0] = -cVector3::Dot(vecRight, *pPosView);
	resultM.m_arr[0][1] = vecUp.x;
	resultM.m_arr[1][1] = vecUp.y;
	resultM.m_arr[2][1] = vecUp.z;
	resultM.m_arr[3][1] = -cVector3::Dot(vecUp, *pPosView);
	resultM.m_arr[0][2] = vecLook.x;
	resultM.m_arr[1][2] = vecLook.y;
	resultM.m_arr[2][2] = vecLook.z;
	resultM.m_arr[3][2] = -cVector3::Dot(vecLook, *pPosView);
	resultM.m_arr[3][3] = 1;
	return resultM;
}


cMatrix4 cMatrix4::View(cVector4* pPosView, cVector3* pVecLook, cVector3* pVecUp, cVector3* pVecRight)
{
	cMatrix4 resultM;

	resultM.m_arr[0][0] = pVecRight->x;
	resultM.m_arr[1][0] = pVecRight->y;
	resultM.m_arr[2][0] = pVecRight->z;
	resultM.m_arr[3][0] = -cVector3::Dot(*pVecRight, *pPosView);
	resultM.m_arr[0][1] = pVecUp->x;
	resultM.m_arr[1][1] = pVecUp->y;
	resultM.m_arr[2][1] = pVecUp->z;
	resultM.m_arr[3][1] = -cVector3::Dot(*pVecUp, *pPosView);
	resultM.m_arr[0][2] = pVecLook->x;
	resultM.m_arr[1][2] = pVecLook->y;
	resultM.m_arr[2][2] = pVecLook->z;
	resultM.m_arr[3][2] = -cVector3::Dot(*pVecLook, *pPosView);
	resultM.m_arr[3][3] = 1;
	return resultM;
}


cMatrix4 cMatrix4::Projection(float fFovY, float fAspect, float fNear, float fFar)
{
	cMatrix4 resultM;
	
	float scaleY = 1.f / (tan(fFovY*RADIAN/2));
	float scaleX = scaleY / fAspect;

	resultM.m_arr[0][0] = scaleX;
	resultM.m_arr[1][1] = scaleY;
	resultM.m_arr[2][2] = fFar / (fFar - fNear);
	resultM.m_arr[3][2] = -(fFar*fNear) / (fFar - fNear);
	resultM.m_arr[2][3] = 1;

	return resultM;
}


cMatrix4 cMatrix4::Viewport(float fWidth, float fHeight)
{
	cMatrix4 resultM = cMatrix::Identity(4);

	resultM.m_arr[0][0] = fWidth / 2;
	resultM.m_arr[1][1] = -fHeight / 2;
	resultM.m_arr[3][0] = fWidth / 2;
	resultM.m_arr[3][1] = fHeight / 2;

	return resultM;
}


cVector4 cMatrix4::operator*(cVector4& vec)	const
{
	cVector4 resultV;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
			resultV(i) += vec(j) * m_arr[j][i];
	}

	resultV.Initialize();
	return resultV;
}


cMatrix4 cMatrix4::operator+(const cMatrix4& matrix)
{
	return cMatrix::operator+(matrix);
}


cMatrix4 cMatrix4::operator-(const cMatrix4& matrix)
{
	return cMatrix::operator-(matrix);
}


cMatrix4 cMatrix4::operator*(const cMatrix4& matrix)
{
	return cMatrix::operator*(matrix);
}


cMatrix4 cMatrix4::operator*(float scalar)
{
	return cMatrix::operator*(scalar);
}


cMatrix4 cMatrix4::operator/(float scalar)
{
	return cMatrix::operator/(scalar);
}


cMatrix4 cMatrix4::operator=(const cMatrix4& matrix)
{
	return cMatrix::operator=(matrix);
}
