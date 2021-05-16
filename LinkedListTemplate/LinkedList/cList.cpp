//#include "stdafx.h"
//#include "cList.h"
//#include "MyFunction.h"
//#include <iostream>
//#include <fstream>
//using namespace std;
//
//
////template <class T>
////cList<T>::cList()
////{
////}
////
////
////template <class T>
////cList<T>::~cList()
////{
////}
//
//
//template <class T>
//void cList<T>::Insert(T val)
//{
//	if (!m_pHead)
//		m_pHead = new cNode(val);
//
//	cNode* pNode = m_pHead;
//
//	while (pNode->m_pNext)
//	{
//		pNode = pNode->m_pNext;
//	}
//
//	pNode->m_pNext = new cNode(val);
//}
//
//
//template <class T>
//void cList<T>::Delete(T val)
//{
//	if (!m_pHead)
//		return;
//
//	cNode* pNode = m_pHead;
//	cNode* pBeforeNode = NULL;
//
//	if (pNode->m_nVal == val)
//	{
//		m_pHead = pNode->m_pNext;
//		delete pNode;
//		return;
//	}
//
//	while (pNode)
//	{
//		pBeforeNode = pNode;
//		pNode = pNode->m_pNext;
//
//		if (pNode->m_nVal == val)
//		{
//			pBeforeNode->m_pNext = pNode->m_pNext;
//			delete pNode;
//			return;
//		}
//	}
//}
//
//
//template <class T>
//void cList<T>::Print()
//{
//	if (!m_pHead)
//		return;
//
//	cNode* pNode = m_pHead;
//	while (pNode->m_pNext)
//	{
//		cout << pNode->m_nVal << endl;
//		pNode = pNode->m_pNext;
//	}
//}
//
//
//template <class T>
//void cList<T>::Reverse()
//{
//	if (!m_pHead)
//		return;
//
//	cNode* pBeforeNode = NULL;
//	cNode* pNode = m_pHead;
//	cNode* pNextNode = pNode->m_pNext;
//
//	pNode->m_pNext = NULL;
//
//	while (pNextNode)
//	{
//		pBeforeNode = pNode;
//		pNode = pNextNode;
//		pNextNode = pNextNode->m_pNext;
//
//		pNode->m_pNext = pBeforeNode;
//	}
//	
//	m_pHead = pNode;
//}
//
//
//template <class T>
//void cList<T>::GetScript(char* strFileName)
//{
//	char strIn[20];
//
//	ifstream scriptFile(strFileName);
//
//	while (!scriptFile.eof())
//	{
//		scriptFile.getline(strIn, 20);
//		UppercaseToLowercase(strIn);
//		ProcessScript(strIn);
//	}
//
//	scriptFile.close();
//}
//
//
//template <class T>
//void cList<T>::ProcessScript(char* strCommand)
//{
//	int val;
//
//	if (CommandCheck(strCommand, "insert:"))
//	{
//		if (GetIntFromString(strCommand, &val))
//			Insert(val);
//
//		return;
//	}
//
//	if (CommandCheck(strCommand, "delete:"))
//	{
//		if (GetIntFromString(strCommand, &val))
//			Delete(val);
//
//		return;
//	}
//
//	if (CommandCheck(strCommand, "reverse"))
//	{
//		Reverse();
//		return;
//	}
//
//	if (CommandCheck(strCommand, "print"))
//	{
//		Print();
//		return;
//	}
//}