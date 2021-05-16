#include "stdafx.h"
#include "Calculator.h"


Calculator::Calculator()
{
}


Calculator::~Calculator()
{
}


void Calculator::ReadFile(char* strFileName)
{
	char str[100];

	ifstream ifQuestion(strFileName);
	ifQuestion.getline(str, 100);
	ifQuestion.close();

	int i = 0;
	bool bPositive = true;

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			AddFloatInBinomial(str, &i, &bPositive);
			continue;
		}

		switch (str[i])
		{
		case '+': case '*': case '/': case '(': case ')':
			m_arrExpession[m_nLen++] = cBinomial(0, str[i]);
			break;
		case '-':
			if (!m_arrExpession[m_nLen - 1].IsOperator())
			{
				m_arrExpession[m_nLen++] = cBinomial(0, '+');
			}
			bPositive = false;
			break;
		}
		++i;
	}
}


void Calculator::Calculate()
{
	cBinomial* pHead;


}

void Calculator::AddFloatInBinomial(char* str, int* pIndex, bool* pbPositive)
{
	float fVal = str[(*pIndex)++] - '0';

	while (str[*pIndex] >= '0' && str[*pIndex] <= '9')
	{
		fVal *= 10;
		fVal += str[(*pIndex)++] - '0';
	}

	if (str[(*pIndex)] == '.')
	{
		++(*pIndex);
		while (str[*pIndex] >= '0' && str[*pIndex] <= '9')
		{
			fVal += (str[(*pIndex)++] - '0')*0.1;
		}
	}

	if (!(*pbPositive))
		fVal *= -1;

	*pbPositive = true;

	m_arrExpession[m_nLen++] = cBinomial(fVal);
}
