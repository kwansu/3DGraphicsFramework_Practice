#include "stdafx.h"
#include "cObject.h"


cpDDevice*	cObject::s_ppDDevice = NULL;

cObject::cObject()
	: m_fRotX(0), m_fRotY(0), m_fRotZ(0), m_vecPos(0, 0, 0)
	, m_vecLook(0, 0, 1), m_vecRight(1, 0, 0), m_vecUp(0, 1, 0)
{
	D3DXMatrixIdentity(&m_matWorld);
}


cObject::~cObject()
{
}


cVec3* cObject::GetPosition()
{
	return &m_vecPos;
}


void cObject::SetWorldMatrix()
{
	cMatrixA matTrans, matRotX, matRotY;

	D3DXMatrixRotationX(&matRotX, D3DXToRadian(m_fRotX));
	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fRotY));
	D3DXMatrixTranslation(&matTrans, m_vecPos.x, m_vecPos.y, m_vecPos.z);

	m_matWorld = matRotX * matRotY * matTrans;
}


void cObject::SetLookDirect()
{
	cMatrixA matRotX, matRotY;

	D3DXMatrixRotationX(&matRotX, D3DXToRadian(m_fRotX));
	D3DXMatrixRotationY(&matRotY, D3DXToRadian(m_fRotY));

	D3DXVec3TransformNormal(&m_vecLook, &cVec3(0, 0, 1),
		&(matRotX * matRotY));
}


void cObject::SetRotation(float rotX, float rotY, float rotZ)
{
	m_fRotX = rotX;
	m_fRotY = rotY;
	m_fRotZ = rotZ;
}
