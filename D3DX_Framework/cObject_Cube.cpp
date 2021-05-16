#include "stdafx.h"
#include "cObject_Cube.h"


cObject_Cube::cObject_Cube()
{
	D3DCOLOR c;
	c = D3DCOLOR_XRGB(53, 53, 53);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, -1), c));

	c = D3DCOLOR_XRGB(83, 83, 83);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));

	c = D3DCOLOR_XRGB(113, 113, 113);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, -1), c));

	c = D3DCOLOR_XRGB(143, 143, 143);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, 1), c));

	c = D3DCOLOR_XRGB(173, 173, 173);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, 1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, 1, -1), c));

	c = D3DCOLOR_XRGB(203, 203, 203);
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(-1, -1, 1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, -1), c));
	m_aVertex.push_back(stVertex_PC(D3DXVECTOR3(1, -1, 1), c));
}


cObject_Cube::~cObject_Cube()
{
}


void cObject_Cube::Setup()
{
}


void cObject_Cube::Update()
{
}


void cObject_Cube::Render()
{
	g_pDDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pDDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12,
		&m_aVertex[0], sizeof(stVertex_PC));
}
