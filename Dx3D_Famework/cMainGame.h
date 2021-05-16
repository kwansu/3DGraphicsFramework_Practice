#pragma once
#include "stdObject.h"

class cMainGame
{
private:
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pDDevice;

	DWORD	m_tElapseTime;
	DWORD	m_tExitTime;
	DWORD	m_tFrameTime;
	float	m_fFPS;

	// 오브젝트
	cObject_Camera*		m_pCamera;
	cObject_Grid*		m_pGrid;
	cObject_Cube*		m_pCube;
	cObject_Way*		m_pLook;
	cObject_Way*		m_pUp;
	cObject_Way*		m_pRight;

public:
	cMainGame();
	~cMainGame();

	void Initialize();
	void Release();
	void Run();
	void Update();
	void Render();
};

