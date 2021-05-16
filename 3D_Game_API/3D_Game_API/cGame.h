#pragma once
#include "cMatrix4.h"

class cGame
{
protected:
	static cGame* m_this;

	HWND	m_hWnd;
	HDC		m_hdc;

	DWORD m_tElapse;
	DWORD m_tEnd;
	DWORD m_tFrameTime;
	float m_fFps;

	vector<cVector4> m_arrVertex;
	vector<cVector4> m_arrTrans;

private:
	cGame();
	~cGame();
public:
	static cGame* GetGameSingleTone();

	void Initialize(HWND hWnd);
	void Run();
	void Update();
	void Render();
	void Release();
};

