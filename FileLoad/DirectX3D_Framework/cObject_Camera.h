#pragma once
#include "cObject.h"

#define g_pCamera	cObject_Camera::GetInstance()
#define CAMERA_MOVE_SPEED	0.1f
#define CAMERA_ROTATE_SPEED	0.35f
#define CAMERA_ZOOM_SPEED	0.01f

class cObject_Camera :
	public cObject
{
	SINGLETONE(cObject_Camera);

private:
	float		m_fDistance;
	float		m_fFOV;
	float		m_fNear;
	float		m_fFar;

	cVec3		*m_pvTargetPos, m_vDefault;
	cMatrixA	m_matView;
	cMatrixA	m_matProj;

	RECT		m_rcClient;

public:
	void Setup();
	void Update();
	void Render();
	void SetTarget(cVec3* pvTargetPos);
	void UpdateView();
	void UpdateProjection();
	void GetMouseLine(OUT cVec3* pvDir, OUT cVec3* pvPos);
};

