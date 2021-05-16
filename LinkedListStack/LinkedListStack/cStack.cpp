#include "stdafx.h"
#include "cStack.h"
#include <fstream>
#include "MyFunction.h"
using namespace std;


cStack::cStack()
{
}


cStack::~cStack()
{
}


void cStack::Push(int nVal)
{
	m_list.InsertFront(nVal);
}


void cStack::Pop()
{
	m_list.Delete();
}


void cStack::Print()
{
	m_list.Print();
}


bool cStack::ReadFile(char* strFileName)
{
	char strCommand[20];

	ifstream ifData(strFileName);

	if (!ifData.is_open())
	{
		cout << "file read failed!" << endl;
		return false;
	}

	while (!ifData.eof())
	{
		ifData.getline(strCommand, 20);
		ProcessCommand(strCommand);
	}

	ifData.close();

	return true;
}


void cStack::ProcessCommand(char* strCommand)
{
	int val;

	if (CommandCheck(strCommand, "push"))
	{
		if (GetIntFromString(strCommand, &val))
			Push(val);

		return;
	}

	if (CommandCheck(strCommand, "pop"))
	{
		Pop();
		return;
	}

	if (CommandCheck(strCommand, "print"))
	{
		Print();
		return;
	}
}
