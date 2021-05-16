#pragma once
#include "cObject.h"
#include "cObject_Mesh.h"

class cObject_Plane :
	public cObject
{
	vector<Vertex_PN>	m_aVertex;
	D3DMATERIAL9		m_mtl;

public:
	cObject_Mesh**		m_pPicked;
	cObject_Plane();
	~cObject_Plane();
	void Setup();
	void Update();
	void Render();
	void SetXY();
	void SetYZ();
};

