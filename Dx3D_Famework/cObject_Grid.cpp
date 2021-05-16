#include "stdafx.h"
#include "cObject_Grid.h"


cObject_Grid::cObject_Grid()
{
	Setup(20, 1.0f);
}


cObject_Grid::~cObject_Grid()
{
}


void cObject_Grid::Setup(int nLine, float fDistance)
{
	if (!m_aVectex.empty())
		m_aVectex.clear();

	float fHalfSide = nLine * fDistance;
	for (int i = -nLine; i <= nLine; i += 2)
	{
		xColor color = (i % 5) ? D3DCOLOR_XRGB(128, 128, 128)
			: D3DCOLOR_XRGB(255, 255, 255);

		m_aVectex.push_back(cVertex_PC(i*fDistance, 0, fHalfSide, color));
		m_aVectex.push_back(cVertex_PC(i*fDistance, 0, -fHalfSide, color));
		m_aVectex.push_back(cVertex_PC(fHalfSide, 0, i*fDistance, color));
		m_aVectex.push_back(cVertex_PC(-fHalfSide, 0, i*fDistance, color));
	}

	m_aVectex.push_back(cVertex_PC(fHalfSide, 0, 0, D3DCOLOR_XRGB(255, 0, 0)));
	m_aVectex.push_back(cVertex_PC(-fHalfSide, 0, 0, D3DCOLOR_XRGB(255, 0, 0)));
	m_aVectex.push_back(cVertex_PC(0, 0, fHalfSide, D3DCOLOR_XRGB(0, 0, 255)));
	m_aVectex.push_back(cVertex_PC(0, 0, -fHalfSide, D3DCOLOR_XRGB(0, 0, 255)));
	m_aVectex.push_back(cVertex_PC(0, fHalfSide, 0, D3DCOLOR_XRGB(0, 255, 0)));
	m_aVectex.push_back(cVertex_PC(0, -fHalfSide, 0, D3DCOLOR_XRGB(0, 255, 0)));
}


void cObject_Grid::Render()
{
	(*s_ppDDevice)->SetTransform(D3DTS_WORLD, &m_matWorld);
	(*s_ppDDevice)->DrawPrimitiveUP(D3DPT_LINELIST, m_aVectex.size()/2,
		&m_aVectex[0], sizeof(cVertex_PC));
}


void cObject_Grid::Update()
{
}
