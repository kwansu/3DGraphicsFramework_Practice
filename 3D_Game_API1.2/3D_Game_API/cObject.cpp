#include "stdafx.h"
#include "cObject.h"

cInput* cObject::s_pInput = NULL;


cObject::cObject()
	: m_pos(0, 0, 0, 1), m_vecLook(0, 1, 0)
	, m_vecRight(1, 0, 0), m_vecUp(0, 0, 1)
	, m_fAngleX(0), m_fAngleY(0), m_fAngleZ(0)
{
}


cObject::~cObject()
{
}


void cObject::Translate(cVector3 vecDistance)
{
	Translate(vecDistance.x, vecDistance.y, vecDistance.z);
}


void cObject::Translate(float dx, float dy, float dz)
{
	m_pos = cMatrix4::Translate(dx, dy, dz) * m_pos;
}


// 자신의 로컬좌표에서 회전.
void cObject::RotateX(float fAngle)
{
	m_vecLook = cMatrix4::RotateX(fAngle) * (cVector4)m_vecLook;
}


void cObject::RatateY(float fAngle)
{
	m_vecLook = cMatrix4::RotateY(fAngle) * (cVector4)m_vecLook;
}


void cObject::RotateZ(float fAngle)
{
	m_vecLook = cMatrix4::RotateZ(fAngle) * (cVector4)m_vecLook;
}


// 로컬좌표 크기변경. 각 버텍스의 로컬좌표 변화
void cObject::Magnify(float fRatio)
{
}


void cObject::LookAt(cVector4 posAt)
{
	m_vecLook = (posAt - m_pos).Normalize();
	m_vecRight = cVector3::Cross(m_vecUp.Normalize(), m_vecLook);
	m_vecUp = cVector3::Cross(m_vecLook, m_vecRight);
}


cMatrix4 cObject::GetWorldConvert()
{
	return cMatrix4::Translate(m_pos);
}
