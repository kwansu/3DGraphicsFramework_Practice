#pragma once
#include "stdObjects.h"
#include "cEditer.h"

class cMainGame
{
private:
	// ������Ʈ ������ �ʱ�ȭ
	cObject_Camera*		m_pCamera;
	cGrid*				m_pGrid;
	cObject_Map*		m_pMap;

	D3DLIGHT9			m_light;

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

