#pragma once
#include "cReferrers.h"

#define g_pRefCounter cReferenceCounter::GetInstance()

// ���α׷��� �����Ҵ��ϴ� ��ü�� �������̺�.
class cReferenceCounter
{
	friend class cReferrers;
	SINGLETONE(cReferenceCounter);

private:
	set<cReferrers*>	m_setReferrers;

private:
	void AddReference(cReferrers* pReferrers);
	void RemovecReference(cReferrers* pReferrers);

public:
	void Destroy();
};

