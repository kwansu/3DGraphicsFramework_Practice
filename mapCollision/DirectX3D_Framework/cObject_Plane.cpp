#include "stdafx.h"
#include "cObject_Plane.h"


cObject_Plane::cObject_Plane()
{
	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, -10), cVec3(0, 1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, 10), cVec3(0, 1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, 10), cVec3(0, 1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, -10), cVec3(0, 1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, 10), cVec3(0, 1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, -10), cVec3(0, 1, 0)));

	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, -10), cVec3(0, -1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, 10), cVec3(0, -1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, 10), cVec3(0, -1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(-10, 0, -10), cVec3(0, -1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, -10), cVec3(0, -1, 0)));
	m_aVertex.push_back(Vertex_PN(cVec3(10, 0, 10), cVec3(0, -1, 0)));

	ZeroMemory(&m_mtl, sizeof(D3DMATERIAL9));
	m_mtl.Emissive = xColor(1.0f, 0, 0, 1.0f);
	m_mtl.Power = 10.f;
}


cObject_Plane::~cObject_Plane()
{
}


void cObject_Plane::Setup()
{
}


void cObject_Plane::Update()
{
}


void cObject_Plane::Render()
{
	m_vPos = (*m_pPicked)->m_vPos;

	UpdateWorld();
	g_pDevice->SetMaterial(&m_mtl);
	g_pDevice->SetTransform(D3DTS_WORLD, &m_matWolrd);
	g_pDevice->SetFVF(Vertex_PN::FVF);
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST
		, m_aVertex.size() / 3, &m_aVertex[0], sizeof(Vertex_PN));
}


void cObject_Plane::SetXY()
{
	//m_aVertex[0].pos = cVec3(-10, -10, 0);
	//m_aVertex[1].pos = cVec3(-10, 10, 0);
	//m_aVertex[2].pos = cVec3(10, 10, 0);
	//m_aVertex[3].pos = cVec3(-10, -10, 0);
	//m_aVertex[4].pos = cVec3(10, 10, 0);
	//m_aVertex[5].pos = cVec3(10, -10, 0);
	m_fAngleX = 90;
	m_mtl.Emissive = xColor(0, 1.0f, 0, 1.0f);
}


void cObject_Plane::SetYZ()
{
	m_fAngleX = 90;
	m_fAngleY = 90;
	m_mtl.Emissive = xColor(0, 0, 1.0f, 1.0f);
}
