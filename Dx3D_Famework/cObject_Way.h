#pragma once
#include "cObject.h"

class cObject_Way :
	public cObject
{
private:
	vector<cVec3>		m_av;
	vector<cPolygon>	m_aPolygon;

public:
	cObject_Way(xColor color);
	~cObject_Way();

	void Render();
	void Update();
	void Setup();
};

