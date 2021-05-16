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
		}
	}

	m_pMesh->Update();
}


void cObjectsManager::Render()
{
	m_pMesh->Render();
}


void cObjectsManager::IsPickedObject()
{
	if (m_pMesh->IsPicked(m_vDir, m_vPos))
		m_pPicked = m_pMesh;
	else
		m_pPicked = NULL;
}
