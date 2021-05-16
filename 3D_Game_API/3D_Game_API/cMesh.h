#pragma once
#include "cPolygon.h"

class cMesh
{
protected:
	vector<cVector4> m_arrVertex;
	vector<cVector4> m_arrVertexCopy;
	vector<cPolygon> m_arrMeshData;

public:
	static HDC s_hdc;

	cMesh();
	~cMesh();
	virtual void Draw(const cMatrix4& mVeiwConvert);
	bool IsFront(int& i);
};

