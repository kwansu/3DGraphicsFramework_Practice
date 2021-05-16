#include "stdafx.h"
#include "cObject_Box.h"


cObject_Box::cObject_Box()
	:m_nPower(0)
{
}


cObject_Box::~cObject_Box()
{
}


void cObject_Box::Draw(cMatrix4 mViewConvert)
{
	cMesh::Draw(cMatrix4::RotateZ(m_fAngleZ) * GetWorldConvert() * mViewConvert);
}


void cObject_Box::Update()
{
	m_vecLook = cMatrix4::RotateZ(m_fAngleZ)*cVector4(0, 1, 0, 0);
	//박스의 이동 및 회전.
	if (GetAsyncKeyState(VK::W) * 0x8000)
		m_pos = m_pos - (cVector4)(m_vecLook * BOX_MOVE_SPEED);

	if (GetAsyncKeyState(VK::S) * 0x8000)
		m_pos = m_pos + (cVector4)(m_vecLook * BOX_MOVE_SPEED);

	if (GetAsyncKeyState(VK::A) * 0x8000)
		m_fAngleZ -= BOX_ROTATE_SPEED;

	if (GetAsyncKeyState(VK::D) * 0x8000)
		m_fAngleZ += BOX_ROTATE_SPEED;

	if (m_nPower)
	{
		m_pos.z += (m_nPower - 80) * 0.01f;
		m_nPower -= 10;
	}
	else
		if (GetAsyncKeyState(VK_SPACE) * 0x8000)
			m_nPower = 150;
}
