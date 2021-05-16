#include "stdafx.h"
#include "cMesh.h"


cMesh::cMesh()
	: m_pMtl(NULL), m_pTexture(NULL)
{
}


cMesh::~cMesh()
{
}


void cMesh::Render()
{
	if (m_pTexture)
		g_pDevice->SetTexture(0, m_pTexture);

	g_pDevice->SetFVF(Vertex_PNT::FVF);
	g_pDevice->SetMaterial(m_pMtl);
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST
		, m_aVertex.size() / 3, &m_aVertex[0], sizeof(Vertex_PNT));
}


void cMesh::SetMaterial(cMaterial* pMtl)
{
	m_pMtl = pMtl->GetMaterial();
	m_pTexture = pMtl->GetTextrue();
}


void cMesh::PushVertex(const Vertex_PNT* pVertex)
{
	m_aVertex.push_back(*pVertex);
}


bool cMesh::IsPicked(const cVec3* pvDir, const cVec3* pvPos)
{
	cVec3 v2, v3, n, p, p1, p2, p3;
	float fVal;

	int size = m_aVertex.size();
	for (int i = 0; i < size; i += 3)
	{
		v2 = m_aVertex[i + 1].p - m_aVertex[i].p;
		v3 = m_aVertex[i + 2].p - m_aVertex[i].p;

		D3DXVec3Cross(&n, &v2, &v3);
		fVal = D3DXVec3Dot(&n, pvDir);

		if (fVal < D3DX_16F_EPSILON)
			continue;

		fVal = D3DXVec3Dot(&(m_aVertex[i].p - *pvPos), &n) / fVal;
		p = *pvPos + fVal * *pvDir;
		
		p1 = m_aVertex[i].p - p;
		p2 = m_aVertex[i + 1].p - p;
		p3 = m_aVertex[i + 2].p - p;
		D3DXVec3Normalize(&p1, &p1);
		D3DXVec3Normalize(&p2, &p2);
		D3DXVec3Normalize(&p3, &p3);

		fVal = acos(D3DXVec3Dot(&p1, &p2)) + acos(D3DXVec3Dot(&p1, &p3))
			+ acos(D3DXVec3Dot(&p3, &p2));

		if (fVal >= 2 * D3DX_PI - D3DX_16F_EPSILON)
			return true;
	}

	return false;
}
