#pragma once
#include "stVertex.h"

class cObject
{
protected:
	cVec3		m_vecPos;
	cVec3		m_vecLook, m_vecUp, m_vecRight;
	float		m_fAngleX, m_fAngleY, m_fAngleZ;
	cMatrixA	m_matWorld, m_matScale;
	cMatrixA	m_matPos, m_matRotX, m_matRotY;

public:
	cObject();
	~cObject();
	
	// 오브젝트 인터페이스
	virtual void Setup() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	void SetPosition(float _x, float _y, float _z);
	void SetPosition(cVec3* pPos);
	void SetRotation(float angleX, float angleY, float angleZ);
	void SetScale(float sx, float sy, float sz);
	void UpdateWorldMatrix();
	cVec3* GetPosition();
};

