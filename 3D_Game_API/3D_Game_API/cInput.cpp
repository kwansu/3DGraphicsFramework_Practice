#include "stdafx.h"
#include "cInput.h"

cInput* cInput::s_this = NULL;


cInput::cInput()
	: m_fDistanceX(0), m_fDistanceY(0)
	, m_nMouseWheel(0)
{
}


cInput::~cInput()
{
}


cInput* cInput::GetInput()
{
	if (!s_this)
		s_this = new cInput;

	return s_this;
}


void cInput::Update()
{
	m_fDistanceX = m_fMouseX - m_fBeforeX;
	m_fDistanceY = m_fMouseY - m_fBeforeY;

	m_fBeforeX = m_fMouseX;
	m_fBeforeY = m_fMouseY;

	if (m_nMouseWheel)
		m_nMouseWheel += (m_nMouseWheel < 0 ? 30 : -20);
}
