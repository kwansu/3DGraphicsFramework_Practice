#pragma once
#include <iostream>

class cNode
{
public:
	int m_val;
	cNode* m_pNext;
	
	cNode(int nVal, cNode* pNext = NULL)
		: m_val(nVal), m_pNext(pNext)
	{}

	void Delete()
	{
		if (m_pNext)
			m_pNext->Delete();

		delete this;
	}

	void Print()
	{
		std::cout << m_val << std::endl;
	}
};


class cList
{
private:
	cNode* m_pHead;

public:
	cList();
	~cList();
	void InsertFront(int nVal);
	void Delete();
	void Print();
	void DeleteAll();
};

