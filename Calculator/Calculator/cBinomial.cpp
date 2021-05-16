#include "stdafx.h"
#include "cBinomial.h"


cBinomial::cBinomial()
	: m_fVal(0), m_cOper(NULL)
	, m_pLeft(NULL), m_pRight(NULL)

{
}


cBinomial::cBinomial(float fVal, char cOper)
	: m_fVal(fVal), m_cOper(cOper)
	, m_pLeft(NULL), m_pRight(NULL)

{
}


cBinomial::~cBinomial()
{
}


float cBinomial::GetResult()
{
	return 0;
}


bool cBinomial::IsOperator()
{
	if (m_cOper)
		return true;

	return false;
}
