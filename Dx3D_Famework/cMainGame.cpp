#include "stdafx.h"
#include "cMainGame.h"


cMainGame::cMainGame()
	: m_pD3D(NULL), m_pDDevice(NULL)
{
}


cMainGame::~cMainGame()
{
	SAFE_RELEASE(m_pD3D);
	SAFE_RELEASE(m_pDDevice);
	SAFE_RELEASE(g_pInput);
	delete m_pCamera;
	delete m_pGrid;
	delete m_pCube;
	delete m_pLook;
	delete m_pUp;
	delete m_pRight;
}


void cMainGame::Initialize()
{
	m_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DCAPS9	stCaps;
	int			nVertexProcessing;
	m_pD3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &stCaps);
	
	if (stCaps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		nVertexProcessing = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		nVertexProcessing = D3DCREATE_SOFTWARE_VERTEXPROCESSING;

	D3DPRESENT_PARAMETERS	stDPP;
	ZeroMemory(&stDPP, sizeof(D3DPRESENT_PARAMETERS));
	stDPP.AutoDepthStencilFormat = D3DFMT_D16;
	stDPP.BackBufferFormat = D3DFMT_UNKNOWN;
	stDPP.EnableAutoDepthStencil = TRUE;
	stDPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	stDPP.Windowed = TRUE;

	m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, g_hWnd,
		nVertexProcessing, &stDPP, &m_pDDevice);

	m_pDDevice->SetRenderState(D3DRS_LIGHTING, false);

	cObject::s_ppDDevice = &m_pDDevice;

	// 오브젝트 생성 및 초기화:
	m_pCamera = new cObject_Camera;
	m_pGrid = new cObject_Grid;
	m_pCube = new cObject_Cube;
	m_pLook = new cObject_Way(D3DCOLOR_XRGB(0, 0, 255));
	m_pUp = new cObject_Way(D3DCOLOR_XRGB(0, 255, 0));
	m_pRight = new cObject_Way(D3DCOLOR_XRGB(255, 0, 0));
	m_pCamera->Setup(m_pCube);
	m_pUp->SetRotation(-90, 0, 0);
	m_pRight->SetRotation(0, 90, 0);
}


void cMainGame::Release()
{
}


void cMainGame::Run()
{
	m_tElapseTime = GetTickCount() - m_tExitTime;

	if (m_tElapseTime < m_tFrameTime)
		Sleep(m_tFrameTime - m_tElapseTime);

	Update();
	Render();
}


void cMainGame::Update()
{
	g_pInput->Update();
	m_pCamera->Update();
	m_pCube->Update();
}


void cMainGame::Render()
{
	m_pDDevice->Clear(NULL, NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(190, 190, 190), 1.0f, 0);

	m_pDDevice->BeginScene();

	// Draw
	m_pDDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE);
	m_pGrid->Render();
	m_pCube->Render();
	m_pLook->Render();
	m_pUp->Render();
	m_pRight->Render();


	m_pDDevice->EndScene();
	m_pDDevice->Present(NULL, NULL, NULL, NULL);
}

