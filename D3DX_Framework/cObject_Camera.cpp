#include "stdafx.h"
#include "cObject_Camera.h"


cObject_Camera::cObject_Camera()
	: m_fDistance(10), m_fFar(1000), m_fFOV(45)
	, m_fNear(1), m_pVecTargetPos(NULL), m_vecOri(0, 0 ,0)
{
	D3DXMatrixIdentity(&m_matProj);
	D3DXMatrixIdentity(&m_matView);
}


cObject_Camera::~cObject_Camera()
{
}


void cObject_Camera::Setup()
{
	m_vecPos = cVec3(0, 10, 10);
	UpdateProjection();
}


void cObject_Camera::Update()
{
	UpdateView();
	UpdateWorldMatrix();
}


void cObject_Camera::Render()
{
}


void cObject_Camera::UpdateView()
{
	if (!m_pVecTargetPos)
		m_pVecTargetPos = &m_vecOri;

	D3DXMatrixLookAtLH(&m_matView, &m_vecPos,
		m_pVecTargetPos, &cVec3(0, 1, 0));

	g_pDDevice->SetTransform(D3DTS_VIEW, &m_matView);
}


void cObject_Camera::UpdateProjection()
{
	RECT rcClient;
	GetClientRect(g_hWnd, &rcClient);

	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DXToRadian(m_fFOV),
		(float)rcClient.right / rcClient.bottom,
		m_fNear, m_fFar);

	g_pDDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
}


void cObject_Camera::SetTarget(cObject* pTarget)
{
	m_pVecTargetPos = pTarget->GetPosition();
}
