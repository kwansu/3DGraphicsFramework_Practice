#include "stdafx.h"
#include "cObject_Cube.h"


cObject_Cube::cObject_Cube()
	: m_fMoveSpeed(0.1f), m_fRotateSpeed(5)
	, m_nPower(0), m_nAccel(2), m_nJumpHeight(80)
{
	m_av.push_back(cVec3(-1, -1, -1));
	m_av.push_back(cVec3(-1,	  1, -1));
	m_av.push_back(cVec3( 1,  1, -1));
	m_av.push_back(cVec3( 1, -1, -1));
	m_av.push_back(cVec3(-1, -1,  1));
	m_av.push_back(cVec3(-1,  1,  1));
	m_av.push_back(cVec3( 1,  1,  1));
	m_av.push_back(cVec3( 1, -1,  1));

	m_aPolygon.push_back(cPolygon(m_av[0], m_av[1], m_av[2], D3DCOLOR_XRGB(240, 240, 240)));
	m_aPolygon.push_back(cPolygon(m_av[0], m_av[2], m_av[3], D3DCOLOR_XRGB(240, 240, 240)));

	m_aPolygon.push_back(cPolygon(m_av[4], m_av[6], m_av[5], D3DCOLOR_XRGB(100, 100, 100)));
	m_aPolygon.push_back(cPolygon(m_av[4], m_av[7], m_av[6], D3DCOLOR_XRGB(100, 100, 100)));

	m_aPolygon.push_back(cPolygon(m_av[4], m_av[5], m_av[1], D3DCOLOR_XRGB(126, 126, 126)));
	m_aPolygon.push_back(cPolygon(m_av[4], m_av[1], m_av[0], D3DCOLOR_XRGB(126, 126, 126)));

	m_aPolygon.push_back(cPolygon(m_av[3], m_av[2], m_av[6], D3DCOLOR_XRGB(200, 200, 200)));
	m_aPolygon.push_back(cPolygon(m_av[3], m_av[6], m_av[7], D3DCOLOR_XRGB(200, 200, 200)));

	m_aPolygon.push_back(cPolygon(m_av[1], m_av[5], m_av[6], D3DCOLOR_XRGB(168, 168, 168)));
	m_aPolygon.push_back(cPolygon(m_av[1], m_av[6], m_av[2], D3DCOLOR_XRGB(168, 168, 168)));

	m_aPolygon.push_back(cPolygon(m_av[4], m_av[0], m_av[3], D3DCOLOR_XRGB(50, 50, 50)));
	m_aPolygon.push_back(cPolygon(m_av[4], m_av[3], m_av[7], D3DCOLOR_XRGB(50, 50, 50)));

	m_vecPos.y = 1;
}


cObject_Cube::~cObject_Cube()
{
}


void cObject_Cube::Update()
{
	SetLookDirect();

	if (GetAsyncKeyState('W') & 0x8000)
		m_vecPos += m_vecLook * m_fMoveSpeed;

	if (GetAsyncKeyState('S') & 0x8000)
		m_vecPos -= m_vecLook * m_fMoveSpeed;

	if (GetAsyncKeyState('A') & 0x8000)
		m_fRotY -= m_fRotateSpeed;

	if (GetAsyncKeyState('D') & 0x8000)
		m_fRotY += m_fRotateSpeed;

	if (m_nPower)
	{
		m_vecPos.y += 0.01*(m_nPower - (m_nJumpHeight + m_nAccel)/2);
		m_nPower -= m_nAccel;
	}
	else
		if (GetAsyncKeyState(VK_SPACE) & 0x8000)
			m_nPower = m_nJumpHeight;
}


void cObject_Cube::Render()
{
	SetWorldMatrix();

	(*s_ppDDevice)->SetTransform(D3DTS_WORLD, &m_matWorld);
	(*s_ppDDevice)->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12,
		&m_aPolygon[0], sizeof(cVertex_PC));
}


void cObject_Cube::Setup()
{
}
