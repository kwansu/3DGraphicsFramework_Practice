#include "stdafx.h"
#include "cObject_Collider.h"


cObject_Collider::cObject_Collider()
{
	D3DCOLOR c = D3DCOLOR_XRGB(30, 200, 30);

	m_aVertex.push_back(Vertex_PC(cVec3(-1, -1, -1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(1, -1, -1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(1, -1, 1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(-1, -1, 1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(-1, 1, -1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(1, 1, -1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(1, 1, 1), c));
	m_aVertex.push_back(Vertex_PC(cVec3(-1, 1, 1), c));

	m_aIndexBuffer[0] = 0;	m_aIndexBuffer[1] = 1;
	m_aIndexBuffer[2] = 1;	m_aIndexBuffer[3] = 2;
	m_aIndexBuffer[4] = 2;	m_aIndexBuffer[5] = 3;
	m_aIndexBuffer[6] = 3;	m_aIndexBuffer[7] = 0;
	m_aIndexBuffer[8] = 0;	m_aIndexBuffer[9] = 4;
	m_aIndexBuffer[10] = 1;	m_aIndexBuffer[11] = 5;
	m_aIndexBuffer[12] = 2;	m_aIndexBuffer[13] = 6;
	m_aIndexBuffer[14] = 3;	m_aIndexBuffer[15] = 7;
	m_aIndexBuffer[16] = 4;	m_aIndexBuffer[17] = 5;
	m_aIndexBuffer[18] = 5;	m_aIndexBuffer[19] = 6;
	m_aIndexBuffer[20] = 6;	m_aIndexBuffer[21] = 7;
	m_aIndexBuffer[22] = 7;	m_aIndexBuffer[23] = 4;
}


cObject_Collider::cObject_Collider(cMatrixA* mat)
: cObject_Collider()
{
	m_pmatParent = mat;
}



cObject_Collider::~cObject_Collider()
{
}


void cObject_Collider::Setup()
{
}


void cObject_Collider::Update()
{
	m_vMin = cVec3(FLT_MAX, FLT_MAX, FLT_MAX);
	m_vMax = cVec3(-FLT_MAX, -FLT_MAX, -FLT_MAX);
	cVec3 aVertex[8];

	for (int i = 0; i < 8; ++i)
		D3DXVec3TransformCoord(&(aVertex[i]), &(m_aVertex[i].pos), m_pmatParent);

	D3DXComputeBoundingBox(&aVertex[0], 8, sizeof(cVec3), &m_vMin, &m_vMax);
}


void cObject_Collider::Render()
{
	cMatrixA matTrans = m_matWolrd;

	if (m_pmatParent)
		matTrans *= *m_pmatParent;

	//g_pDevice->SetRenderState(D3DRS_LIGHTING, false);

	//g_pDevice->SetTransform(D3DTS_WORLD, &matTrans);
	//g_pDevice->SetFVF(Vertex_PC::FVF);
	//g_pDevice->DrawIndexedPrimitiveUP(D3DPT_LINELIST, 0, 8
	//	, 12, m_aIndexBuffer, D3DFMT_INDEX32
	//	, &m_aVertex[0], sizeof(Vertex_PC));

	//g_pDevice->SetRenderState(D3DRS_LIGHTING, true);

	g_pDevice->SetTransform(D3DTS_WORLD, &m_matWolrd);

	g_pDevice->SetFVF(D3DFVF_XYZ | D3DFVF_NORMAL);
	g_pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_aVertex.size() / 3, &m_aVertex[0], sizeof(Vertex_PC));
	g_pDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
}


bool cObject_Collider::IsCollision(OUT cVec3* pvOverap, cObject_Collider* pCollider)
{
	//	Update();
	pCollider->Update();
	cVec3 vMax = pCollider->m_vMax;
	cVec3 vMin = pCollider->m_vMin;

	if (m_vMin.x > vMax.x || vMin.x > m_vMax.x)
		return false;
	pvOverap->x = (m_vMax.x - vMin.x > vMax.x - m_vMin.x) ?
		vMax.x - m_vMin.x : -(m_vMax.x - vMin.x);

	if (m_vMin.y > vMax.y || vMin.y > m_vMax.y)
		return false;
	pvOverap->y = (m_vMax.y - vMin.y > vMax.y - m_vMin.y) ?
		vMax.y - m_vMin.y : -(m_vMax.y - vMin.y);

	if (m_vMin.z > vMax.z || vMin.z > m_vMax.z)
		return false;
	pvOverap->z = (m_vMax.z - vMin.z > vMax.z - m_vMin.z) ?
		vMax.z - m_vMin.z : -(m_vMax.z - vMin.z);

	return true;
}


bool cObject_Collider::CollisionCheck(OUT cVec3 vPos, OUT float* dist)
{
	cMatrixA mat;

	float a;
	
//	D3DXVec3TransformCoord(&vPos, &vPos, &mat);
	cVec3 line[2];
	vPos.y += 1000;
	line[0] = vPos;

	int size = m_aVertex.size();
	for (int i = 0; i < size; i += 3)
	{
		if (D3DXIntersectTri(&m_aVertex[i].pos
			, &m_aVertex[i + 1].pos, &m_aVertex[i + 2].pos
			, &vPos, &cVec3(0, -1, 0), &a, &a, dist))
		{
			line[1] = vPos;
			line[1].y -= *dist;
			*dist -= 1000;
			return true;
		}
	}

	g_pDevice->SetFVF(D3DFVF_XYZ );
	g_pDevice->DrawPrimitiveUP(D3DPT_LINELIST
		, 1, line, sizeof(cVec3));

	return false;
}
