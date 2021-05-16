#pragma once

class cVertex_PC
{
protected:
	cVec3	m_vecPos;
	xColor	m_color;

public:
	cVertex_PC();
	cVertex_PC(cVec3 vec, xColor color);
	cVertex_PC(float x, float y, float z, xColor color);
	~cVertex_PC();
};

