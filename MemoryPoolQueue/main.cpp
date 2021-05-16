// ListQueue.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <Windows.h>
#include "stdafx.h"
#include "cListQueue.h"
#include "MemoryPoolQueue.h"
#include "cCircluarQueue.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cCircluarQueue	circQueue;
	cListQueue		listQueue;

	circQueue.ReadFile("queue.txt");
	cout << endl;

	listQueue.ReadFile("queue.txt");
	cout << endl;

	int tStart = GetTickCount();

	cListQueue lq;

	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			lq.Enqueue(7);
		}
		for (int j = 0; j < 1000; ++j)
		{
			lq.Dequeue();
		}
	}

	int tEnd = GetTickCount();

	cout << (tEnd - tStart) / 1000.f << endl;

	MemoryPoolQueue mq;

	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			mq.Enqueue(7);
		}
		for (int j = 0; j < 1000; ++j)
		{
			mq.Dequeue();
		}
	}

	tStart = GetTickCount();
	cout << (tStart - tEnd) / 1000.f << endl;

	return 0;
}
