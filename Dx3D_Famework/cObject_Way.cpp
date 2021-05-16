#include "stdafx.h"
#include "cObject_Way.h"


cObject_Way::cObject_Way(xColor color)
{
	m_av.push_back(cVec3(0, 0, 0));
	m_av.push_back(cVec3(-0.236f, 0.236f, 1.2f));
	m_av.push_back(cVec3(0.236f, 0.236f, 1.2f));
	m_av.push_back(cVec3(0.236f, -0.236f, 1.2f));
	m_av.push_back(cVec3(-0.236f, -0.236f, 1.2f));

	m_aPolygon.push_back(cPolygon(m_av[0], m_av[1], m_av[2], color));
	m_aPolygon.push_back(cPolygon(m_av[0], m_av[2], m_av[3], color));
	m_aPolygon.push_back(cPolygon(m_av[0], m_av[3], m_av[4], color));
	m_aPolygon.push_back(cPolygon(m_av[0], m_av[4], m_av[1], color));
	m_aPolygon.push_back(cPolygon(m_av[1], m_av[4], m_av[2], color));
	m_aPolygon.push_back(cPolygon(m_av[2], m_av[4], m_av[3], color));
}


cObject_Way::~cObject_Way()
{
}


void cObject_Way::Render()
{
	SetWorldMatrix();

	(*s_ppDDevice)->SetTransform(D3DTS_WORLD, &m_matWorld);
	(*s_ppDDevice)->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 6,
		&m_aPolygon[0], sizeof(cVertex_PC));
}


void cObject_Way::Update()
{
}


void cObject_Way::Setup()
{
}
