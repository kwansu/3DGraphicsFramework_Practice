#include "stdafx.h"
#include "cMianGame.h"


cMianGame::cMianGame()
{
}


cMianGame::~cMianGame()
{
	// ���� ���� ������ ����̽� ���� ��
	// ��ü�� ����� �Ҹ�Ǿ����� Ȯ���Ѵ�.
	cDeviceManager::GetInstance()->Release();
	g_pRefCounter->Destroy();
}


void cMianGame::Initialize()
{
}


void cMianGame::Release()
{
}


void cMianGame::Run()
{
	g_pTimeManager->WaitFrameTime();

	Update();
	Render();
}


void cMianGame::Update()
{
	g_pInput->Update();

}


void cMianGame::Render()
{
	g_pDevice->Clear(NULL, NULL
		, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER
		, D3DCOLOR_XRGB(190, 190, 190)
		, 1.0f, 0);
	g_pDevice->BeginScene();

	// ������ :



	// ������
	g_pDevice->EndScene();
	g_pDevice->Present(NULL, NULL, NULL, NULL);
}


void cMianGame::MessageHandler(HWND hWnd, UINT iMsg, WPARAM wp, LPARAM lp)
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
