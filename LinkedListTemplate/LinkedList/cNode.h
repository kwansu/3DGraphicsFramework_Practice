#pragma once

template <class T>
class cNode
{
public:
	cNode(T val, cNode<T>* pNext = NULL)
		:m_nVal(val), m_pNext(pNext)
	{}
	~cNode()
	{}

	T m_nVal;
	cNode<T>* m_pNext;
};

