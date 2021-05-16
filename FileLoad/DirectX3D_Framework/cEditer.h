#pragma once

class cEditer
{
private:
	cObject*	m_pPicked;
	cVec3		m_vDir, m_vPos;
	int			m_num;
	char		m_str[10];

public:
	cEditer();
	~cEditer();
	
	void Update();
};

