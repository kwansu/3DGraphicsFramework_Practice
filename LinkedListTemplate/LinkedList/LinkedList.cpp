// LinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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

