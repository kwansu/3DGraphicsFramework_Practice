#pragma once

class cMesh
{
protected:
	vector<Vertex_PNT>	m_aVertex;
	vector<cVec3>		m_aPosition;
	vector<cVec3>		m_aNormal;
	vector<cVec2>		m_aTexturePos;
	stMaterial			m_mtl;

public:
	cMesh();
	~cMesh();
	void PushPosition(cVec3* pVec);
	void PushNormal(cVec3* pVec);
	void PushTexturePos(cVec2* pVec);
	void PushVertexPNT(int aPNT[3]);
	void SetMaterial(stMaterial* pMtl);
	void Render();
};

