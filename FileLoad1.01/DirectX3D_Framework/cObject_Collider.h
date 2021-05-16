#pragma once
#include "cObject.h"

class cObject_Collider :
	public cObject
{
protected:
	vector<Vertex_PC>	m_aVertex;
	int					m_aIndexBuffer[24];
	cVec3				m_vMax, m_vMin;

protected:
	cMatrixA*			m_pmatParent;

public:
	cObject_Collider();
	cObject_Collider(cMatrixA* mat);
	~cObject_Collider();
	void Setup();
	void Update();
	void Render();
	bool IsCollision(OUT cVec3* pvOverap, cObject_Collider* pCollider);
	bool CollisionCheck(OUT cVec3 vPos, OUT float* dist);
};

