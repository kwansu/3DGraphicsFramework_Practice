#pragma once


class cCircluarQueue
{
private:
	int m_arrData[5];
	int m_front;
	int m_rear;

public:
	cCircluarQueue();
	~cCircluarQueue();
	void Enqueue(int val);
	void Dequeue();
	void Print();
	int Increase(int index);
	void ReadFile(char* strFileName);
};

