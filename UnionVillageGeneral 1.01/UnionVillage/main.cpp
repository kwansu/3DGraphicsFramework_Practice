// UnionVillage.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "Resident.h"
#include <queue>


int _tmain(int argc, _TCHAR* argv[])
{
	Resident::SetVillage("data2.txt");

	std::cout << Resident::GetNumberOfHuman() << std::endl;

	Resident::Release();

	return 0;
}

