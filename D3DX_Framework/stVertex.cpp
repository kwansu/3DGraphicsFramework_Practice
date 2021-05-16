#include "stdafx.h"
#include "stVertex.h"


stVertex_PC::stVertex_PC()
	: pos(0, 0, 0), color(D3DCOLOR_XRGB(255, 255, 255))
{
}


stVertex_PC::stVertex_PC(cVec3 _pos, xColor _color)
	: pos(_pos), color(_color)
{
}


stVertex_PC::~stVertex_PC()
{
}
