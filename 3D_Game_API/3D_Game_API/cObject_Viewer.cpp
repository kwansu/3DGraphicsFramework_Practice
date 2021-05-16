#include "stdafx.h"
#include "cObject_Viewer.h"


//cVector4* cObject_Viewer::m_posAt = NULL;

cObject_Viewer::cObject_Viewer()
	: cObject(), m_fDistance(10.f), m_fFovY(90)
{
}


cObject_Viewer::~cObject_Viewer()
{
}


cMatrix4 cObject_Viewer::GetViewConvert()
{
	return cMatrix4::View(&m_pos, m_posAt, &cVector3(0, 0, 1))
		* cMatrix4::Projection(m_fFovY, m_fAspect, m_fNear, m_fFar)
		* cMatrix4::Viewport(m_fWidth, m_fHeight);
}


void cObject_Viewer::SetFovY(float fFovY)
{
	if (fFovY < 10 || fFovY > 180)
		return;

	m_fFovY = fFovY;
}


bool cObject_Viewer::SetViewRange(float fNear, float fFar)
{
	if (fFar < fNear || fNear <= 0)
		return false;
	
	m_fFar = fFar;
	m_fNear = fNear;
	return true;
}


void cObject_Viewer::SetViewSize(float fWidth, float fHeight)
{
	if (fWidth >= 100 && fWidth <= 10000)
		m_fWidth = fWidth;

	if (fHeight >= 100 && fHeight <= 10000)
		m_fHeight = fHeight;
}


void cObject_Viewer::Initialize(HWND hWnd, cVector4* p)
{
	RECT rtClient;
	GetClientRect(hWnd, &rtClient);

	m_posAt = p;

	m_fAspect = rtClient.right / (float)rtClient.bottom;
	m_fFar = 100;
	m_fNear = 1;
	m_pos = cVector4(5, 5, 8, 1);
	LookAt(*m_posAt);
	m_fWidth = rtClient.right;
	m_fHeight = rtClient.bottom;
	m_fDistance = 10;
}


void cObject_Viewer::Update()
{
	m_pos = cMatrix4::RotateX(m_fAngleX) * cMatrix4::RotateZ(m_fAngleZ) * cVector4(0, m_fDistance, 0, 1);
	m_pos = m_pos + *m_posAt;

	//마우스 이동및 회전.
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (m_fAngleX + s_pInput->m_fDistanceY * 0.3f > -20 &&
			m_fAngleX + s_pInput->m_fDistanceY * 0.3f < 80)
			m_fAngleX += s_pInput->m_fDistanceY * 0.3f;
		m_fAngleZ += s_pInput->m_fDistanceX * 0.3f;
	}

	if (s_pInput->m_nMouseWheel)
	{
		if (m_fDistance - s_pInput->m_nMouseWheel * 0.005f > 5)
			m_fDistance -= s_pInput->m_nMouseWheel * 0.005f;

		s_pInput->m_nMouseWheel += (s_pInput->m_nMouseWheel > 0) ? -40 : 40;
	}
}


// 중심점을 기준으로 월드좌표 z축 회전, 로컬좌표의 right축 회전
void cObject_Viewer::RotateAt(float fAngleZ, float fAngleR)
{
	float fDistance = (m_pos - *m_posAt).Length();

	//z축 회전.
	Translate(-*m_posAt);
	m_pos = cMatrix4::RotateZ(fAngleZ) * m_pos;
	Translate(*m_posAt);

	LookAt(*m_posAt);

	//right축 회전
	Translate(m_vecLook*fDistance);
	m_vecLook = cos(fAngleR*RADIAN) * m_vecLook + sin(fAngleR*RADIAN) * cVector3::Cross(m_vecRight, m_vecLook);
	Translate(-m_vecLook*fDistance);
}
