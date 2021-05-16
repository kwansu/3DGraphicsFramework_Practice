#pragma once

class cTimeManager
{
	SINGLETONE(cTimeManager);

private:
	float	m_fAverageFPS;			//10�������� ��� FPS
	float	m_fFPS;					//�������ִ� FPS
	DWORD	m_dwFrameTime;			//�� ������ ����

	DWORD	m_dwTickCurrentTime;	//���� ��ǻ�� ƽī����
	DWORD	m_dwTickEndTime;		//������ �������� �ð�
	DWORD	m_dwElapseTime;			//������ ������ ����ð�
	DWORD	m_dwGameTime;			//������ ����ð�

public:
	void SetFPS(float fFPS)		{ m_fFPS = fFPS; }
	float GetFPS()	const		{ return m_fFPS; }
	void WaitFrameTime();
};


extern cTimeManager* g_pTimeManager;