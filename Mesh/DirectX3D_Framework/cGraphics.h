#pragma once
#include "cMesh.h"

#define g_pGraphics	cGraphics::GetInstance()

class cGraphics
{
	SINGLETONE(cGraphics);

private:
	map<string, cMesh>			m_mapMeshData;
	map<string, stMaterial>		m_mapMtlData;
	cMesh*						m_pMeshEdit;
	stMaterial*					m_pMtlEdit;
	pTexture					m_pTexture;

public:
	bool LoadObjFile(char* strFileName);
	bool LoadMtlFile(char* strFileName);
	void Release();
	void Render();
};

