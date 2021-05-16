#include "stdafx.h"
#include "cObject_Camera.h"


cObject_Camera::cObject_Camera()
	: m_fDistance(10.f), m_fFOV(45)
	, m_fNear(1), m_fFar(1000), m_vDefault(0, 0, 0)
{
	D3DXMatrixIdentity(&m_matProj);
	m_matView = m_matProj;
	m_pvTargetPos = &m_vDefault;
}


cObject_Camera::~cObject_Camera()
{
}


void cObject_Camera::Setup()
{
	UpdateProjection();
	m_fAngleX = 40;
}


void cObject_Camera::Update()
{
	UpdateRotation();

	D3DXVec3TransformCoord(&m_vPos,
		&cVec3(0, 0, -m_fDistance), &m_matRot);

	m_vPos += *m_pvTargetPos;

	UpdateView();
}


void cObject_Camera::Render()
{
}


void cObject_Camera::SetTarget(cVec3* pvTargetPos)
{
	m_pvTargetPos = pvTargetPos;
}


void cObject_Camera::UpdateView()
{
	D3DXMatrixLookAtLH(&m_matView, &m_vPos, m_pvTargetPos, &m_vUp);
	g_pDevice->SetTransform(D3DTS_VIEW, &m_matView);
}


void cObject_Camera::UpdateProjection()
{
	RECT rcClient;
	GetClientRect(g_hWnd, &rcClient);
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DXToRadian(m_fFOV),
		rcClient.right / (float)rcClient.bottom, m_fNear, m_fFar);

	g_pDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
}
