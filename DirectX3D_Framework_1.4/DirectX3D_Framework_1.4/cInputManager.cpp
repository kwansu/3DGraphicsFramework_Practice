#include "stdafx.h"
#include "cInputManager.h"


cInputManager* g_pInput = cInputManager::GetInstance();

cInputManager::cInputManager()
	: m_abInputKey()
	, m_abInputKeyBefore()
	, m_nMouseWheel(0)
{
}


cInputManager::~cInputManager()
{
}

void cInputManager::Update()
{
	//if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	//	m_abInputKey[VK_RBUTTON] = true;
	//else
	//	m_abInputKey[VK_RBUTTON] = false;

	//if (GetAsyncKeyState('W') & 0x8000)
	//	m_abInputKey['W'] = true;
	//else
	//	m_abInputKey['W'] = false;

	//if (GetAsyncKeyState('S') & 0x8000)
	//	m_abInputKey['S'] = true;
	//else
	//	m_abInputKey['S'] = false;

	memcpy(&m_abInputKeyBefore, m_abInputKey, sizeof(m_abInputKey));

	if (m_nMouseWheel)
	{
		m_nMouseWheel *= 0.9f;
		if (abs(m_nMouseWheel) < 10)
			m_nMouseWheel = 0;
	}

	GetCursorPos(&m_ptMousePos);

	m_ptMousePosInterval.x = m_ptMousePos.x - m_ptMousePosBefore.x;
	m_ptMousePosInterval.y = m_ptMousePos.y - m_ptMousePosBefore.y;
	m_ptMousePosBefore = m_ptMousePos;
}
