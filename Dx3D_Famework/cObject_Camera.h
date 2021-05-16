#pragma once
#include "cObject.h"
class cObject_Camera :
	public cObject
{
private:
	float		m_fDistance;
	float		m_fFOV;
	float		m_fNear;
	float		m_fFar;
	float		m_fRotSpeed;
	float		m_fZoomSpeed;

	cVec3*		m_pVecTargetPos;
	cMatrixA	m_matView;
	cMatrixA	m_matProj;

public:
	cObject_Camera();
	~cObject_Camera();

	void Setup(cObject* pTarget);
	void SetView();
	void SetProjection();
	void Update();
	void SetTarget(cObject* pTarget);
	void SetPosition();
	void Render();
};

