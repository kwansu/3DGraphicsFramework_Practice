#pragma once
#include "cMatrix4.h"

class cPolygon
{
public:
	int m_nFirst, m_nSecond, m_nThird;

public:
	cPolygon(int nFirst, int nSecond, int nThird);
	~cPolygon();
};

