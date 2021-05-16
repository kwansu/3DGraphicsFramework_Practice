#include "stdafx.h"
#include "cObject_Camera.h"


cObject_Camera::cObject_Camera()
	: m_pVecTargetPos(NULL)
{
}


cObject_Camera::~cObject_Camera()
{
}


void cObject_Camera::Setup(cObject* pTarget)
{
	m_fFar = 1000;
	m_fNear = 1;
	m_fFOV = D3DXToRadian(90);
	m_fDistance = 10.f;
	m_vecPos = cVec3(10, 10, 10);
	m_fRotSpeed = 0.3f;
	m_fZoomSpeed = 0.003f;
	
	SetTarget(pTarget);
	SetView();
	SetProjection();
}


void cObject_Camera::SetView()
{ 
	if (!m_pVecTargetPos)
		return;

	D3DXMatrixLookAtLH(&m_matView, &m_vecPos,
		m_pVecTargetPos, &cVec3(0, 1, 0));

	(*s_ppDDevice)->SetTransform(D3DTS_VIEW, &m_matView);
}


void cObject_Camera::SetProjection()
{
	RECT rcClient;
	GetClientRect(g_hWnd, &rcClient);

	D3DXMatrixPerspectiveFovLH(&m_matProj, m_fFOV,
		(float)rcClient.right / rcClient.bottom,
		m_fNear, m_fFar);

	(*s_ppDDevice)->SetTransform(D3DTS_PROJECTION, &m_matProj);
}


void cObject_Camera::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		m_fRotY += g_pInput->m_nDistanceX * m_fRotSpeed;
		m_fRotX += g_pInput->m_nDistanceY * m_fRotSpeed;
		if (m_fRotX > 80.f) m_fRotX = 80.f;
		if (m_fRotX < -30.f)	 m_fRotX = -30.f;
	}

	if (g_pInput->m_nMouseWheel)
	{
		m_fDistance -= g_pInput->m_nMouseWheel*m_fZoomSpeed;
		g_pInput->m_nMouseWheel += (g_pInput->m_nMouseWheel > 0) ? -20 : 20;
		if (m_fDistance < 3)	m_fDistance = 3;
	}


	SetPosition();
	SetView();
}


void cObject_Camera::SetTarget(cObject* pTarget)
{
	m_pVecTargetPos = pTarget->GetPosition();
}


void cObject_Camera::SetPosition()
{
	cMatrixA matRotX, matRotY;

	D3DXMatrixRotationX(&matRotX, D3DXToRadian(m_fRotX));
	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fRotY));
	matRotX = matRotX * matRotY;

	D3DXVec3TransformCoord(&m_vecPos,
		&cVec3(0, 0, -m_fDistance), &matRotX);

	m_vecPos += *m_pVecTargetPos;
}


void cObject_Camera::Render()
{
}
