#pragma once
#include "cMaterial.h"

class cMesh
{
private:
	vector<Vertex_PNT>	m_aVertex;
	D3DMATERIAL9*		m_pMtl;
	pTexture			m_pTexture;

public:
	cMesh();
	~cMesh();
	void Render();
	void SetMaterial(cMaterial* pMtl);
	void PushVertex(const Vertex_PNT* pVertex);
	bool IsPicked(const cVec3* pvDir, const cVec3* pvPos);
};

