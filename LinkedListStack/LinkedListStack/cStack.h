#pragma once
#include "cList.h"


class cStack
{
private:
	cList m_list;
	
public:
	cStack();
	~cStack();
	void Push(int nVal);
	void Pop();
	void Print();
	bool ReadFile(char* str);
	void ProcessCommand(char* str);
};

