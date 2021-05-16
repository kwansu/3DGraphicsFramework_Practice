#include "stdafx.h"
#include "cObject_Mesh.h"


cObject_Mesh::cObject_Mesh()
{
	SetScale(0.1f, 0.1f, 0.1f);
	m_fAngleX = -90;
}


cObject_Mesh::~cObject_Mesh()
{
}


void cObject_Mesh::Setup()
{
}


void cObject_Mesh::Update()
{
}


void cObject_Mesh::Render()
{
	UpdateWorld();
	g_pDevice->SetTransform(D3DTS_WORLD, &m_matWolrd);
	g_pGraphics->Render();
}


bool cObject_Mesh::IsPicked(cVec3 vDir, cVec3 vPos)
{
	cMatrixA matWorldIn;
	float fVal;

	D3DXMatrixInverse(&matWorldIn, &fVal, &m_matWolrd);

	D3DXVec3TransformCoord(&vPos, &vPos, &matWorldIn);
	D3DXVec3TransformNormal(&vDir, &vDir, &matWorldIn);

	return g_pGraphics->IsPicked(&vDir, &vPos);
}


void cObject_Mesh::MoveObject(cVec3* pvDir, cVec3* pvPos, cVec3* pvNormal)
{
	float ratio = D3DXVec3Dot(&(m_vPos - *pvPos), pvNormal)
		/ D3DXVec3Dot(pvDir, pvNormal);

	m_vPos = *pvPos + ratio * *pvDir;
}


void cObject_Mesh::ConvertSize(cVec3* pvDir)
{
	*pvDir *= g_pInput->GetMouseInterval().x;

	cMatrixA matSize;

	D3DXMatrixScaling(&matSize, pvDir->x, pvDir->y, pvDir->z);

	m_matScale *= matSize;
}
