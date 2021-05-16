#include "stdafx.h"
#include "cVertex_PC.h"


cVertex_PC::cVertex_PC()
{
}


cVertex_PC::cVertex_PC(cVec3 vec, xColor color)
	: m_vecPos(vec), m_color(color)
{
}


cVertex_PC::cVertex_PC(float x, float y, float z, xColor color)
	: m_vecPos(x, y, z), m_color(color)
{
}


cVertex_PC::~cVertex_PC()
{
}
