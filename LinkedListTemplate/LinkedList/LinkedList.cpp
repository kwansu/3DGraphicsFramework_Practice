// LinkedList.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "cList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cList<char*> list;

	list.Insert("afdf");
	list.Insert("305 9sf");
	list.Reverse();
	list.Print();
	list.Delete("afdf");
	list.Print();

//	list.GetScript("test.txt");
	return 0;
}

