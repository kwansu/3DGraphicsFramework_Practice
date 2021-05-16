#pragma once
#include "cObject.h"

class cObject_Structure
{
protected:
	cMesh*		m_pMesh;
	cCollider*	m_pCollider;
	
public:
	cObject_Structure();
	~cObject_Structure();
};

