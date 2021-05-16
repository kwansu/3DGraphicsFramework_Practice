#pragma once
#include "cMesh.h"

#define g_pGraphics	cGraphics::GetInstance()

class cGraphics
{
	SINGLETONE(cGraphics);

private:
	map<string, cMesh>		m_mapMeshData;
	map<string, cMaterial>	m_mapMtlData;
	map<string, pTexture>	m_mapTexture;

public:
	pTexture				m_ptexMario;
	bool LoadObjFile(char* strFileName);
	bool LoadMtlFile(char* strFileName);
	void Release();
	void Render();
	bool IsPicked(const cVec3* pvDir, const cVec3* pvPos);
};

