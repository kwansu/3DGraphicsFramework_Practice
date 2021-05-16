#include "stdafx.h"
#include "cNode.h"
#include <iostream>


cNode::cNode(int val, cNode* pNext)
	: m_val(val), m_pNext(pNext)
{
}


cNode::~cNode()
{
}


void cNode::Print()
{
	std::cout << m_val << std::endl;
}


void cNode::Release()
{
	if (m_pNext)
		m_pNext->Release();

	delete this;
}
