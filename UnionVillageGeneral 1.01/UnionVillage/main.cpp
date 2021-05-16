// UnionVillage.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

