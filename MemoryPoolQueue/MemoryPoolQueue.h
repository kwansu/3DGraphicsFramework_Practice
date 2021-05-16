#pragma once
#include "cNode.h"


class MemoryPoolQueue
{
private:
	cNode* m_pFront;
	cNode* m_pRear;
	cNode* m_pStorage;

public:
	MemoryPoolQueue();
	~MemoryPoolQueue();
	void Enqueue(int val);
	void Dequeue();
	void Print();
};

