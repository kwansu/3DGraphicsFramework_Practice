#include "stdafx.h"
#include "cMesh.h"


cMesh::cMesh()
{
	ZeroMemory(&m_mtl, sizeof(stMaterial));
}


cMesh::~cMesh()
{
}


void cMesh::PushPosition(cVec3* pVec)
{
	m_aPosition.push_back(*pVec);
}


void cMesh::PushNormal(cVec3* pVec)
{
	m_aNormal.push_back(*pVec);
}


void cMesh::PushTexturePos(cVec2* pVec)
{
	m_aTexturePos.push_back(*pVec);
}


void cMesh::PushVertexPNT(int aPNT[3])
{
	m_aVertex.push_back(Vertex_PNT(m_aPosition[aPNT[0]]
		, m_aNormal[aPNT[2]], m_aTexturePos[aPNT[1]]));
}


void cMesh::SetMaterial(stMaterial* pMtl)
{
	m_mtl = *pMtl;
}


void cMesh::Render()
{
	g_pDevice->SetMaterial(&m_mtl);
	g_pDevice->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1);
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_aVertex.size() / 3, &m_aVertex[0], sizeof(Vertex_PNT));
}
