#include "stdafx.h"
#include "Resident.h"
#include "MyFunction.h"
using namespace std;


bool* Resident::m_arrCheckList = NULL;
Resident* Resident::m_arrResidents = NULL;
int Resident::m_nResiLen = 0;
stack<int> Resident::m_document;


Resident::Resident()
{
}


Resident::~Resident()
{
	delete[] m_arrInfo;
}


void Resident::SetVillage(char* strFileName)
{
	char strLine[100];

	ifstream ifFileData(strFileName);
	
	ifFileData.getline(strLine, 100);
	m_nResiLen = atoi(strLine);

	m_arrCheckList = new bool[m_nResiLen];
	m_arrResidents = new Resident[m_nResiLen];

	for (int i = 0; i < m_nResiLen; ++i)
	{
		ifFileData.getline(strLine, 100);
		m_arrResidents[i].SetResidentInfo(strLine);
	}

	ifFileData.close();
}


void Resident::SetResidentInfo(char* strLine)
{
	char* tem = strLine;
	GetNextInt(tem);
	m_nInfoLen = GetNextInt(tem);

	m_arrInfo = new int[m_nInfoLen];

	for (int i = 0; i < m_nInfoLen; ++i)
		m_arrInfo[i] = GetNextInt(tem) - 1;
}


void Resident::CheckHumanInfo()
{
	m_document.pop();

	for (int i = 0; i < m_nInfoLen; ++i)
	{
		m_document.push(m_arrInfo[i]);
	}
}


int Resident::GetNumberOfHuman()
{
	m_document.push(0);

	while (!m_document.empty())
	{
		if (m_arrCheckList[(m_document.top())])
		{
			m_arrCheckList[(m_document.top())] = false;
			m_arrResidents[(m_document.top())].CheckHumanInfo();
			continue;
		}
		m_document.pop();
	}

	int nCount = 0;

	for (int i = 0; i < m_nResiLen; ++i)
	{
		if (!m_arrCheckList[i])
			++nCount;
	}

	return nCount;
}


void Resident::Release()
{
	delete[] m_arrCheckList;
	delete[] m_arrResidents;
}
