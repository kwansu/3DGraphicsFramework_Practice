#include "stdafx.h"
#include "MemoryPoolQueue.h"


MemoryPoolQueue::MemoryPoolQueue()
	: m_pFront(NULL), m_pRear(NULL), m_pStorage(0)
{
}


MemoryPoolQueue::~MemoryPoolQueue()
{
	if (m_pFront)
		m_pFront->Release();

	if (m_pStorage)
		m_pStorage->Release();
}


void MemoryPoolQueue::Enqueue(int val)
{
	if (m_pStorage)
	{
		cNode* pNode = m_pStorage;
		m_pStorage = m_pStorage->m_pNext;

		pNode->m_val = val;
		pNode->m_pNext = NULL;

		if (!m_pRear)
		{
			m_pFront = pNode;
			m_pRear = m_pFront;
			return;
		}
		m_pRear->m_pNext = pNode;
		m_pRear = m_pRear->m_pNext;
	}
	else
	{

		if (!m_pRear)
		{
			m_pRear = new cNode(val);
			m_pFront = m_pRear;
			return;
		}
		m_pRear->m_pNext = new cNode(val);
		m_pRear = m_pRear->m_pNext;
	}
}


void MemoryPoolQueue::Dequeue()
{
	if (!m_pFront)
		return;

	if (m_pFront == m_pRear)
	{
		cNode* pNode = m_pFront;
		m_pFront = m_pFront->m_pNext;

		pNode->m_pNext = m_pStorage;
		m_pStorage = pNode;

		m_pFront = NULL;
		m_pRear = NULL;
		return;
	}

	cNode* pNode = m_pFront;
	m_pFront = m_pFront->m_pNext;

	pNode->m_pNext = m_pStorage;
	m_pStorage = pNode;
}


void MemoryPoolQueue::Print()
{
	cNode* pNode = m_pFront;
	while (pNode)
	{
		pNode->Print();
		pNode = pNode->m_pNext;
	}
}
