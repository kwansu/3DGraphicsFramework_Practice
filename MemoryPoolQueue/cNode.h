#pragma once


class cNode
{
public:
	cNode* m_pNext;
	int m_val;
	int m_garbage[1000];

public:
	cNode(int val, cNode* pNext = NULL);
	~cNode();
	void Print();
	void Release();
};

