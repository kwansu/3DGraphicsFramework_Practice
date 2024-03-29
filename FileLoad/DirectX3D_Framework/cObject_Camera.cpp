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

	if (g_pInput->IsKeyPress(VK_RBUTTON))
	{
		m_fAngleX += g_pInput->GetMouseInterval().y * CAMERA_ROTATE_SPEED;
		m_fAngleY += g_pInput->GetMouseInterval().x * CAMERA_ROTATE_SPEED;

		if (m_fAngleX > 80) m_fAngleX = 80;
		if (m_fAngleX < -20) m_fAngleX = -20;
	}

	if (g_pInput->GetMouseWheel())
		m_fDistance -= g_pInput->GetMouseWheel() * CAMERA_ZOOM_SPEED;

	if (m_fDistance < 5)
		m_fDistance = 5;

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
	GetClientRect(g_hWnd, &m_rcClient);
	D3DXMatrixPerspectiveFovLH(&m_matProj, D3DXToRadian(m_fFOV),
		m_rcClient.right / (float)m_rcClient.bottom, m_fNear, m_fFar);

	g_pDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);
}


void cObject_Camera::GetMouseLine(OUT cVec3* pvDir, OUT cVec3* pvPos)
{
	cMatrixA matViewIn, matProjIn, matWorldIn;

	float fVal;
	D3DXMatrixInverse(&matViewIn, &fVal, &m_matView);
	D3DXMatrixInverse(&matProjIn, &fVal, &m_matProj);
	matWorldIn = matProjIn * matViewIn;

	POINT mousePos = g_pInput->GetMousePos();
	pvDir->x = (mousePos.x * 2.f / m_rcClient.right) - 1.f;
	pvDir->y = -(mousePos.y * 2.f / m_rcClient.bottom) + 1.f;
	pvDir->z = 0;
	
	cVec3 endPos = *pvDir;
	endPos.z = 1;

	D3DXVec3TransformCoord(pvDir, pvDir, &matWorldIn);
	D3DXVec3TransformCoord(&endPos, &endPos, &matWorldIn);

	*pvDir -= endPos;
	D3DXVec3Normalize(pvDir, pvDir);

	D3DXVec3TransformCoord(pvPos, pvPos, &matWorldIn);
}


