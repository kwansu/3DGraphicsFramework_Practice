#pragma once
#include "stdObject.h"

class cGame
{
private:
	static cGame* s_this;
protected:
	HWND	m_hWnd;
	HDC		m_hdc, m_hBufferDC;

	HBITMAP m_bmpBack;
	cInput* m_pInput;

	DWORD m_tElapse;
	DWORD m_tEnd;
	DWORD m_tFrameTime;
	float m_fFps;

	vector<cVector4> m_arrVertex;
	vector<cVector4> m_arrTrans;

	//오브젝트생성
	cObject_Viewer* m_pViewer;
	cObject_Box* m_pBox;

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
	void GraphicsInit();
	void GraphicsRelease();
	HRESULT MessageHandler(UINT iMsg, WPARAM wp, LPARAM lp);
};

