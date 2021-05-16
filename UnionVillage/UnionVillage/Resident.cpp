#include "stdafx.h"
#include "Resident.h"
#include "MyFunction.h"
using namespace std;


bool* Resident::m_arrCheckList = NULL;
Resident* Resident::m_arrResidents = NULL;
int Resident::m_nResiLen = 0;


Resident::Resident()
{
}


Resident::~Resident()
{
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

	m_arrCheckList[0] = false;

	ifFileData.close();
}


void Resident::SetResidentInfo(char* strLine)
{
	GetNextInt(strLine);
	m_nInfoLen = GetNextInt(strLine);

	m_arrInfo = new int[m_nInfoLen];

	for (int i = 0; i < m_nInfoLen; ++i)
		m_arrInfo[i] = GetNextInt(strLine) - 1;
}


void Resident::CheckHumanInfo()
{
	for (int i = 0; i < m_nInfoLen; ++i)
	{
		if (m_arrCheckList[(m_arrInfo[i])])
		{
			m_arrCheckList[(m_arrInfo[i])] = false;
			m_arrResidents[(m_arrInfo[i])].CheckHumanInfo();
		}
	}
}


int Resident::GetNumberOfHuman()
{
	int nCount = 0;

	m_arrResidents[0].CheckHumanInfo();

	for (int i = 0; i < m_nResiLen; ++i)
	{
		if (!m_arrCheckList[i])
			++nCount;
	}

	return nCount;
}
