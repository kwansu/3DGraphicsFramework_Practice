#pragma once
#include "cNode.h"


class cListQueue
{
	cNode* m_pFront;
	cNode* m_pRear;

public:
	cListQueue();
	~cListQueue();
	void Enqueue(int val);
	void Dequeue();
	void Print();
	void ReadFile(char* strFileName);
};

