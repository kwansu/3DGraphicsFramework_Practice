#pragma once
class cBinomial
{
private:
	float		m_fVal;
	char		m_cOper;
	cBinomial*	m_pLeft;
	cBinomial*	m_pRight;

public:
	cBinomial();
	cBinomial(float fVal, char cOper = NULL);
	~cBinomial();
	float GetResult();
	bool IsOperator();
};

