#pragma once
#include "cObject.h"

class cObject_Cube :
	public cObject
{
private:
	vector<stVertex_PC>	m_aVertex;

public:
	cObject_Cube();
	~cObject_Cube();

	void Setup();
	void Update();
	void Render();
};

