#pragma once
#include "cObject.h"

class cObject_Cube :
	public cObject
{
private:
	vector<cVec3>		m_av;
	vector<cPolygon>	m_aPolygon;

	int		m_nPower;
	int		m_nAccel;
	int		m_nJumpHeight;
	float	m_fMoveSpeed;
	float	m_fRotateSpeed;

public:
	cObject_Cube();
	~cObject_Cube();

	void Update();
	void Render();
	void Setup();
};

