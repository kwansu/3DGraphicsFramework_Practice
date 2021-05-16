#include "stdafx.h"
#include "cObjectsManager.h"


cObjectsManager::cObjectsManager()
	: m_pMesh(NULL), m_pPicked(NULL)
{
}


cObjectsManager::~cObjectsManager()
{
	SAFE_DELETE(m_pMesh);
}


void cObjectsManager::Setup()
{
	m_pMesh = new cObject_Mesh;
	m_pPlaneXZ.m_pPicked = &m_pPicked;
	m_pPlaneXY.m_pPicked = &m_pPicked;
	m_pPlaneXY.SetXY();
	m_pPlaneYZ.m_pPicked = &m_pPicked;
	m_pPlaneYZ.SetYZ();

}


void cObjectsManager::Update()
{
	g_pCamera->GetMouseLine(&m_vDir, &m_vPos);

	if (g_pInput->IsKeyPress(VK_LBUTTON))
	{
		if (m_pPicked)
		{
			if (g_pInput->IsKeyPress('Z'))
				m_pPicked->MoveObject(&m_vDir, &m_vPos, &cVec3(0, 0, 1));

			if (g_pInput->IsKeyPress('X'))
				m_pPicked->MoveObject(&m_vDir, &m_vPos, &cVec3(1, 0, 0));

			if (g_pInput->IsKeyPress('C'))
				m_pPicked->MoveObject(&m_vDir, &m_vPos, &cVec3(0, 1, 0));

			//if (g_pInput->IsKeyPress('A'))
			//	m_pPicked->ConvertSize(&cVec3(1, 0, 0));

			if (g_pInput->IsKeyPress('S'))
				m_pPicked->ConvertSize(&cVec3(1, 1, 1));

			//if (g_pInput->IsKeyPress('D'))
			//	m_pPicked->ConvertSize(&cVec3(0, 0, 1));
		}
	}

	m_pMesh->Update();
}


void cObjectsManager::Render()
{
	m_pMesh->Render();

	if (m_pPicked)
	{
		if (g_pInput->IsKeyPress('Z'))
			m_pPlaneXY.Render();
		if (g_pInput->IsKeyPress('C'))
			m_pPlaneXZ.Render();
		if (g_pInput->IsKeyPress('X'))
			m_pPlaneYZ.Render();
	}
}


void cObjectsManager::IsPickedObject()
{
	if (m_pMesh->IsPicked(m_vDir, m_vPos))
		m_pPicked = m_pMesh;
	else
		m_pPicked = NULL;
}
