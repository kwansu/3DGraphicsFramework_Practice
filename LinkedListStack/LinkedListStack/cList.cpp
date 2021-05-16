#include "stdafx.h"
#include "cList.h"


cList::cList()
{
}


cList::~cList()
{
}


void cList::InsertFront(int nVal)
{
	cNode* pNode = m_pHead;

	m_pHead = new cNode(nVal);
	m_pHead->m_pNext = pNode;
}


void cList::Delete()
{
	if (!m_pHead)
		return;

	cNode* pNode = m_pHead;

	m_pHead = m_pHead->m_pNext;
	delete pNode;
}


void cList::Print()
{
	cNode* pNode = m_pHead;

	while (pNode)
	{
		pNode->Print();
		pNode = pNode->m_pNext;
	}
}


void cList::DeleteAll()
{
	m_pHead->Delete();
}