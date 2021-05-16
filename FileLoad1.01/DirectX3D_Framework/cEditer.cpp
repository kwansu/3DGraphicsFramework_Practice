#include "stdafx.h"
#include "cEditer.h"


cEditer::cEditer()
	:m_pPicked(NULL)
{
}


cEditer::~cEditer()
{
}


void cEditer::Update()
{
	//if (g_pInput->IsKeyPress(VK_LBUTTON))
	//{
	//	g_pCamera->GetMouseLine(&m_vDir, &m_vPos);
	//	m_pPicked = g_pObjects->IsPickedObject(m_vDir, m_vPos);
	//	if (m_pPicked)
	//		++m_num;
	//}

	wsprintf(m_str, "%d", m_num);
	SetWindowText(g_hWnd, m_str);
}
