#pragma once
#include "cNode.h"
#include "MyFunction.h"
#include <iostream>
#include <fstream>
using namespace std;


template <class T>
class cList
{
private:
	cNode<T>* m_pHead;

public:
	cList() : m_pHead(NULL)
	{}
	~cList()
	{}
	void Insert(T val);
	void Delete(T val);
	void Print();
	void Reverse();
	void GetScript(char* chFileName);
	void ProcessScript(char* strCommand);
};


//template <class T>
//cList<T>::cList()
//{
//}
//
//
//template <class T>
//cList<T>::~cList()
//{
//}


template <class T>
void cList<T>::Insert(T val)
{
	if (!m_pHead)
	{
		m_pHead = new cNode<T>(val);
		return;
	}

	cNode<T>* pNode = m_pHead;

	while (pNode->m_pNext)
	{
		pNode = pNode->m_pNext;
	}

	pNode->m_pNext = new cNode<T>(val);
}


template <class T>
void cList<T>::Delete(T val)
{
	if (!m_pHead)
		return;

	cNode<T>* pNode = m_pHead;
	cNode<T>* pBeforeNode = NULL;

	if (pNode->m_nVal == val)
	{
		m_pHead = pNode->m_pNext;
		delete pNode;
		return;
	}

	while (pNode->m_pNext)
	{
		pBeforeNode = pNode;
		pNode = pNode->m_pNext;

		if (pNode->m_nVal == val)
		{
			pBeforeNode->m_pNext = pNode->m_pNext;
			delete pNode;
			return;
		}
	}
}


template <class T>
void cList<T>::Print()
{
	if (!m_pHead)
		return;

	cNode<T>* pNode = m_pHead;
	while (pNode)
	{
		cout << pNode->m_nVal << endl;
		pNode = pNode->m_pNext;
	}
}


template <class T>
void cList<T>::Reverse()
{
	if (!m_pHead)
		return;

	cNode<T>* pBeforeNode = NULL;
	cNode<T>* pNode = m_pHead;
	cNode<T>* pNextNode = pNode->m_pNext;

	pNode->m_pNext = NULL;

	while (pNextNode)
	{
		pBeforeNode = pNode;
		pNode = pNextNode;
		pNextNode = pNextNode->m_pNext;

		pNode->m_pNext = pBeforeNode;
	}

	m_pHead = pNode;
}


template <class T>
void cList<T>::GetScript(char* strFileName)
{
	char strIn[20];

	ifstream scriptFile(strFileName);

	while (!scriptFile.eof())
	{
		scriptFile.getline(strIn, 20);
		UppercaseToLowercase(strIn);
		ProcessScript(strIn);
	}

	scriptFile.close();
}


template <class T>
void cList<T>::ProcessScript(char* strCommand)
{
	T val;

	if (CommandCheck(strCommand, "insert:"))
	{
		if (GetTemplateFromString(strCommand, &val))
			Insert(val);

		return;
	}

	if (CommandCheck(strCommand, "delete:"))
	{
		if (GetTemplateFromString(strCommand, &val))
			Delete(val);

		return;
	}

	if (CommandCheck(strCommand, "reverse"))
	{
		Reverse();
		return;
	}

	if (CommandCheck(strCommand, "print"))
	{
		Print();
		return;
	}
}


