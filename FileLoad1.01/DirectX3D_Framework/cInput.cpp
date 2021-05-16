#include "stdafx.h"
#include "cInput.h"


cInput::cInput()
	: m_nMouseWheel(0), m_aInputKey()
{
}


cInput::~cInput()
{
}


void cInput::Update()
{
	//m_bLButton = false;

	//if (m_aInputKey[VK_LBUTTON])
	//{
	//	if (!m_bPress)
	//	{
	//		m_bLButton = true;
	//		m_bPress = true;
	//	}
	//}
	//else
	//	m_bPress = false;


	if (m_nMouseWheel)
	{
		m_nMouseWheel *= 0.9f;
		if (abs(m_nMouseWheel) < 10)
			m_nMouseWheel = 0;
	}

	m_ptMouseInterval.x = m_ptMouse.x - m_ptMouseBefore.x;
	m_ptMouseInterval.y = m_ptMouse.y - m_ptMouseBefore.y;
	m_ptMouseBefore = m_ptMouse;
}