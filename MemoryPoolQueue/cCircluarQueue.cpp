#include "stdafx.h"
#include "cCircluarQueue.h"
#include "MyFunction.h"


cCircluarQueue::cCircluarQueue()
	:m_front(0), m_rear(0)
{
}


cCircluarQueue::~cCircluarQueue()
{
}


void cCircluarQueue::Enqueue(int val)
{
	if (Increase(m_rear) == m_front)
		return;

	m_arrData[m_rear] = val;
	m_rear = Increase(m_rear);
}


void cCircluarQueue::Dequeue()
{
	if (m_front == m_rear)
		return;

	m_front = Increase(m_front);
}


void cCircluarQueue::Print()
{
	int index = m_front;
	while (index != m_rear)
	{
		std::cout << m_arrData[index] << std::endl;
		index = Increase(index);
	}
}


int cCircluarQueue::Increase(int index)
{
	if (index == 4)
	{
		index = 0;
		return index;
	}

	return ++index;
}


void cCircluarQueue::ReadFile(char* strFileName)
{
	char strCommand[20];

	ifstream ifScript(strFileName);

	while (!ifScript.eof())
	{
		ifScript.getline(strCommand, 20);

		if (CommandCheck(strCommand, "enqueue:"))
		{
			int val;
			GetIntFromString(strCommand, &val);
			Enqueue(val);
		}
		if (CommandCheck(strCommand, "dequeue:"))
		{
			Dequeue();
		}
		if (CommandCheck(strCommand, "print"))
		{
			Print();
		}
	}

	ifScript.close();
}
