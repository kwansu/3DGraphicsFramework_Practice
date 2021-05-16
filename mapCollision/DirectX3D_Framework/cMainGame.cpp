#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame()
	: m_pCamera(NULL), m_pGrid(NULL), m_pMap(NULL)
{

}


cMainGame::~cMainGame()
{
}


void cMainGame::Initialize()
{
	g_pGraphics->LoadObjFile("map.obj");
	m_pCamera = g_pCamera;
	m_pGrid = new cGrid;
	//m_pMap = new cObject_Map;
	g_pObjects->Setup();

	m_pCamera->Setup();
	m_pGrid->Setup();

	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Diffuse = xColor(1.0f, 1.0f, 1.0f, 1.0f);
	m_light.Ambient = xColor(0.5f, 0.5f, 0.5f, 1.0f);
	m_light.Direction = cVec3(-1, -1, -1);

	g_pDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	g_pDevice->SetLight(1, &m_light);
	g_pDevice->LightEnable(1, true);
}


void cMainGame::Release()
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pMap);

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
	g_pObjects->Update();
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
	//m_pMap->Render();
	g_pObjects->Render();

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
		g_pObjects->IsPickedObject();
		SetCapture(g_hWnd);
		break;
	case WM_LBUTTONUP:
		g_pInput->KeyUp(VK_LBUTTON);
		ReleaseCapture();
		break;
	case WM_RBUTTONDOWN:
		g_pInput->KeyDown(VK_RBUTTON);
		SetCapture(g_hWnd);
		break;
	case WM_RBUTTONUP:
		g_pInput->KeyUp(VK_RBUTTON);
		ReleaseCapture();
		break;
	case WM_MOUSEWHEEL:
		g_pInput->AddWheel(HIWORD(wp));
		break;
	}
}
