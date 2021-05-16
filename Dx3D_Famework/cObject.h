#pragma once
#include "cInput.h"
#include "cPolygon.h"

class cObject
{
protected:
	cVec3		m_vecPos;
	cVec3		m_vecLook, m_vecRight, m_vecUp;
	cMatrixA	m_matWorld;
	float		m_fRotX, m_fRotY, m_fRotZ;

public:
	static cpDDevice*	s_ppDDevice;

public:
	cObject();
	~cObject();

	virtual void Update() = 0;
	virtual void Render() = 0;
	cVec3* GetPosition();
	void SetWorldMatrix();
	void SetLookDirect();
	void SetRotation(float rotX, float rotY, float rotZ);
};

