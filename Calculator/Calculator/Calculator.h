#pragma once
#include "cBinomial.h"


class Calculator
{
private:
	cBinomial m_arrExpession[30];
	int	m_nLen;

public:
	Calculator();
	~Calculator();
	void ReadFile(char* strFileName);
	void Calculate();
	void AddFloatInBinomial(char* str, int* pIndex, bool* pbPositive);
};

