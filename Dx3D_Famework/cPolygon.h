#pragma once
#include "cVertex_PC.h"

class cPolygon
{
private:
	cVertex_PC m_ver1, m_ver2, m_ver3;

public:
	cPolygon();
	cPolygon(cVec3 v1, cVec3 v2, cVec3 v3, xColor color);
	~cPolygon();
};

