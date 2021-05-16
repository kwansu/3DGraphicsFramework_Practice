#pragma once
#include <stack>

class Resident
{
protected:
	static Resident*	m_arrResidents;
	static bool*		m_arrCheckList;
	static int			m_nResiLen;
	static std::stack<int> m_document;


private:
	int*	m_arrInfo;
	int		m_nInfoLen;

//Ŭ���� ���
private:		
	Resident();
	~Resident();
	void SetResidentInfo(char* strLine);
	void CheckHumanInfo();

public:
	static void SetVillage(char* strFileName);
	static int GetNumberOfHuman();
	static void Release();
};

