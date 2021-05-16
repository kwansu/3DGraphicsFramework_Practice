#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
}


void cMainGame::Initialize()
{
	m_pCamera = g_pCamera;
	m_pGrid = new cGrid;
	m_pCamera->Setup();
	m_pGrid->Setup();
}


void cMainGame::Release()
{
	cDevice::GetInstance()->Release(); //디바이스 해체 마지막에.
}


void cMainGame::Run()
{
	g_pTime->AdjustTime();

	Update();
	Render();
}


void cMainGame::Update()
{
	m_pCamera->Update();
}


void cMainGame::Render()
{
	g_pDevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(185, 185, 185),
		1.0f, 0);
	g_pDevice->BeginScene();

	// render:
	m_pGrid->Render();

	// end
	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}


void cMainGame::MessageHandler(UINT iMsg, WPARAM wp, LPARAM lp)
{
}
