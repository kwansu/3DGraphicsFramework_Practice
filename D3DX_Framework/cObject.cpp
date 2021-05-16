#include "stdafx.h"
#include "cObject.h"


cObject::cObject()
	: m_vecLook(0, 0, 1), m_vecRight(1, 0, 0), m_vecUp(0, 1, 0)
	, m_vecPos(0, 0, 0), m_fAngleX(0), m_fAngleY(0), m_fAngleZ(0)
{
	D3DXMatrixIdentity(&m_matScale);
	D3DXMatrixIdentity(&m_matWorld);
	D3DXMatrixIdentity(&m_matPos);
	D3DXMatrixIdentity(&m_matRotX);
	D3DXMatrixIdentity(&m_matRotY);
}


cObject::~cObject()
{
}


void cObject::SetPosition(float _x, float _y, float _z)
{
	m_vecPos = cVec3(_x, _y, _z);
}


void cObject::SetPosition(cVec3* pPos)
{
	m_vecPos = *pPos;
}


void cObject::SetRotation(float angleX, float angleY, float angleZ)
{
	m_fAngleX = angleX;
	m_fAngleY = angleY;
	m_fAngleZ = angleZ;
}


void cObject::SetScale(float sx, float sy, float sz)
{
	D3DXMatrixScaling(&m_matScale, sx, sy, sz);
}


void cObject::UpdateWorldMatrix()
{
	D3DXMatrixTranslation(&m_matPos, m_vecPos.x, m_vecPos.y, m_vecPos.z);
	D3DXMatrixRotationX(&m_matRotX, m_fAngleX);
	D3DXMatrixRotationY(&m_matRotY, m_fAngleY);

	m_matWorld = m_matScale * m_matRotX * m_matRotY * m_matPos;
}


cVec3* cObject::GetPosition()
{
	return &m_vecPos;
}
