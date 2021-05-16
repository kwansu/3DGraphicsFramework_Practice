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

	g_pGraphics->LoadObjFile("map.obj");
}


void cMainGame::Release()
{
	g_pGraphics->Release();
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
	g_pInput->Update();
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
	g_pGraphics->Render();

	// end
	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}


void cMainGame::MessageHandler(UINT iMsg, WPARAM wp, LPARAM lp)
{
	switch (iMsg)
	{
	case WM_KEYDOWN:
		g_pInput->KeyDown(wp);
		break;
	case WM_KEYUP:
		g_pInput->KeyUp(wp);
		break;
	case WM_MOUSEMOVE:
		g_pInput->SetMouse(LOWORD(lp), HIWORD(lp));
		break;
	case WM_LBUTTONDOWN:
		g_pInput->KeyDown(VK_LBUTTON);
		break;
	case WM_LBUTTONUP:
		g_pInput->KeyUp(VK_LBUTTON);
		break;
	case WM_RBUTTONDOWN:
		g_pInput->KeyDown(VK_RBUTTON);
		break;
	case WM_RBUTTONUP:
		g_pInput->KeyUp(VK_RBUTTON);
		break;
	case WM_MOUSEWHEEL:
		g_pInput->AddWheel(HIWORD(wp));
		break;
	}
}
