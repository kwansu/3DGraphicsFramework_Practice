#pragma once
#include "cInput.h"
#include "cMesh.h"

class cObject
{
protected:
	cVector3 m_vecLook, m_vecUp, m_vecRight;
	float m_fAngleX, m_fAngleY, m_fAngleZ;

public:
	cVector4 m_pos;
	static cInput* s_pInput;

	cObject();
	~cObject();
	virtual void Update() = 0;

	void Translate(cVector3 vec);
	void Translate(float dx, float dy, float dz);

	// 자신의 로컬좌표에서 회전.
	void RotateX(float fAngle);
	void RatateY(float fAngle);
	void RotateZ(float fAngle);

	// 로컬좌표 크기변경. 각 버텍스의 로컬좌표 변화
	void Magnify(float fRatio);
	void LookAt(cVector4 posAt);
	cMatrix4 GetWorldConvert();
};

