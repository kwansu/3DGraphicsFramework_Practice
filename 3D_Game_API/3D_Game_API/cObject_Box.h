#pragma once
#include "cObject.h"

class cObject_Box :
	public cObject, cMesh
{
	int m_nPower;

public:
	cObject_Box();
	~cObject_Box();
	void Draw(cMatrix4 mViewConvert);
	void Update();
};

