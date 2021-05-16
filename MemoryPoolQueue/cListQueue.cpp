#include "stdafx.h"
#include "cListQueue.h"
#include "MyFunction.h"


cListQueue::cListQueue()
	:m_pFront(NULL), m_pRear(0)
{
}


cListQueue::~cListQueue()
{
	if (m_pFront)
		m_pFront->Release();
}


void cListQueue::Enqueue(int val)
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


void cListQueue::Dequeue()
{
	if (!m_pFront)
		return;

	if (m_pFront == m_pRear)
	{
		delete m_pFront;
		m_pFront = NULL;
		m_pRear = NULL;
		return;
	}

	cNode* pNode = m_pFront;
	m_pFront = m_pFront->m_pNext;
	delete pNode;
}


void cListQueue::Print()
{
	cNode* pNode = m_pFront;
	while (pNode)
	{
		pNode->Print();
		pNode = pNode->m_pNext;
	}
}


void cListQueue::ReadFile(char* strFileName)
{
	char strCommand[20];

	ifstream ifScript(strFileName);

	while (!ifScript.eof())
	{
		ifScript.getline(strCommand, 20);

		if (CommandCheck(strCommand, "enqueue:"))
		{
			int val;
			GetIntFromString(strCommand, &val);
			Enqueue(val);
		}
		if (CommandCheck(strCommand, "dequeue:"))
		{
			Dequeue();
		}
		if (CommandCheck(strCommand, "print"))
		{
			Print();
		}
	}

	ifScript.close();
}
