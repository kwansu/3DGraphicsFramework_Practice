#pragma once

struct stVertex_PC
{
	cVec3	pos;
	xColor	color;

public:
	stVertex_PC();
	stVertex_PC(cVec3 _pos, xColor _color);
	~stVertex_PC();
};

