#include "stdafx.h"
#include "cInput.h"


cInput* cInput::s_This = NULL;

cInput::cInput()
	: m_nMouseWheel(0)
{
}


cInput::~cInput()
{
}


cInput* cInput::GetInputSingleTone()
{
	if (!s_This)
		s_This = new cInput;

	return s_This;
}


void cInput::Update()
{
	m_nDistanceX = m_nMouseX - m_nBeforeMouseX;
	m_nDistanceY = m_nMouseY - m_nBeforeMouseY;

	m_nBeforeMouseX = m_nMouseX;
	m_nBeforeMouseY = m_nMouseY;

	if (m_nMouseWheel > 480)	m_nMouseWheel = 480;
	if (m_nMouseWheel < -480)	m_nMouseWheel = -480;
}


void cInput::Release()
{
	if (s_This)
		delete s_This;
}
