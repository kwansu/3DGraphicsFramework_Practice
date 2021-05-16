#include "stdafx.h"
#include "cPolygon.h"


cPolygon::cPolygon()
{
}


cPolygon::cPolygon(cVec3 v1, cVec3 v2, cVec3 v3, xColor color)
	: m_ver1(v1, color), m_ver2(v2, color), m_ver3(v3, color)
{
}


cPolygon::~cPolygon()
{
}
