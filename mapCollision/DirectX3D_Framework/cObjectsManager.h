#pragma once
#include "stdObjects.h"

#define g_pObjects cObjectsManager::GetInstance()

class cObjectsManager
{
	SINGLETONE(cObjectsManager);

private:
	cObject_Mesh*	m_pMesh;
	cObject_Mesh*	m_pPicked;

	cObject_Plane	m_pPlaneXZ, m_pPlaneXY, m_pPlaneYZ;

	cVec3			m_vDir, m_vPos;

public:
	void Setup();
	void Update();
	void Render();
	void IsPickedObject();
};

