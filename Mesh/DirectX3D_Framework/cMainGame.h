#pragma once
#include "stdObjects.h"

class cMainGame
{
private:
	// 오브젝트 생성및 초기화
	cObject_Camera*		m_pCamera;
	cGrid*				m_pGrid;

public:
	cMainGame();
	~cMainGame();

	void Initialize();
	void Release();
	void Run();
	void Update();
	void Render();
	void MessageHandler(UINT iMsg, WPARAM wp, LPARAM lp);
};

