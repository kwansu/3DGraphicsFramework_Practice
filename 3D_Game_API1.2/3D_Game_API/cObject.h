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

	// �ڽ��� ������ǥ���� ȸ��.
	void RotateX(float fAngle);
	void RatateY(float fAngle);
	void RotateZ(float fAngle);

	// ������ǥ ũ�⺯��. �� ���ؽ��� ������ǥ ��ȭ
	void Magnify(float fRatio);
	void LookAt(cVector4 posAt);
	cMatrix4 GetWorldConvert();
};

