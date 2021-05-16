#pragma once
#include "cObject.h"

class cObject_Grid :
	public cObject
{
private:
	vector<cVertex_PC>	m_aVectex;
	
public:
	cObject_Grid();
	~cObject_Grid();
	void Setup(int nLine, float fDistance);
	void Render();
	void Update();
};

