// UnionVillage.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Resident.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Resident::SetVillage("data.txt");

	std::cout << Resident::GetNumberOfHuman() << std::endl;

	return 0;
}

