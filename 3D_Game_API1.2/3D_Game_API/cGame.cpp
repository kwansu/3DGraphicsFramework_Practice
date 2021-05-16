#include "stdafx.h"
#include "cGame.h"

cGame* cGame::s_this = NULL;


cGame::cGame()
{
}


cGame::~cGame()
{
}


void cGame::Initialize(HWND hWnd)
{
	m_hWnd = hWnd;

	m_fFps = 30.f;
	m_tFrameTime = 1000.f / m_fFps;

	m_hdc = GetDC(hWnd);
	m_bmpBack = CreateCompatibleBitmap(m_hdc, 1000, 1000);
	ReleaseDC(hWnd, m_hdc);

	//오브젝트의 위치설정 및 초기화
	m_pViewer = new cObject_Viewer;
	m_pBox = new cObject_Box;

	m_pViewer->Initialize(hWnd, &m_pBox->m_pos);

	float fHalf = 5.f;
	for (int x = -5; x <= 5; ++x)
	{
		m_arrVertex.push_back(cVector4(x, fHalf, 0, 1));
		fHalf *= -1;
		m_arrVertex.push_back(cVector4(x, fHalf, 0, 1));
	}
	for (int y = -5; y <= 5; ++y)
	{
		m_arrVertex.push_back(cVector4(fHalf, y, 0, 1));
		fHalf *= -1;
		m_arrVertex.push_back(cVector4(fHalf, y, 0, 1));
	}

	m_arrTrans = m_arrVertex;

	m_pInput = cInput::GetInput();
	cObject::s_pInput = m_pInput;

	m_tEnd = GetTickCount();
}


void cGame::Run()
{
	m_tElapse = GetTickCount() - m_tEnd;

	if (m_tElapse < m_tFrameTime)
		Sleep(m_tFrameTime - m_tElapse);

	Update();
	Render();

	m_tEnd = GetTickCount();
}


void cGame::Update()
{
	m_pInput->Update();
	m_pBox->Update();
	m_pViewer->Update();
}


void cGame::Render()
{
	GraphicsInit();

	cMatrix4 mViewConvert = m_pViewer->GetViewConvert();

	for (int i = 0; i < m_arrVertex.size(); ++i)
		m_arrTrans[i] = mViewConvert * m_arrVertex[i];

	for (int i = 0; i < m_arrVertex.size(); ++i)
	{
		MoveToEx(m_hBufferDC, m_arrTrans[i].x, m_arrTrans[i].y, NULL);
		++i;
		LineTo(m_hBufferDC, m_arrTrans[i].x, m_arrTrans[i].y);
	}

	HPEN hBluePen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN hOldPen = (HPEN)SelectObject(m_hBufferDC, hBluePen);

	MoveToEx(m_hBufferDC, m_arrTrans[10].x, m_arrTrans[10].y, NULL);
	LineTo(m_hBufferDC, m_arrTrans[11].x, m_arrTrans[11].y);

	TextOut(m_hBufferDC, m_arrTrans[11].x, m_arrTrans[11].y, TEXT("Y"), 1);

	HPEN hGreenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
	SelectObject(m_hBufferDC, hGreenPen);

	MoveToEx(m_hBufferDC, m_arrTrans[32].x, m_arrTrans[32].y, NULL);
	LineTo(m_hBufferDC, m_arrTrans[33].x, m_arrTrans[33].y);

	TextOut(m_hBufferDC, m_arrTrans[33].x, m_arrTrans[33].y, TEXT("Z"), 1);

	SelectObject(m_hBufferDC, hOldPen);
	DeleteObject(hBluePen);
	DeleteObject(hGreenPen);

	HBRUSH hBrush = CreateSolidBrush(RGB(125, 0, 125));
	HBRUSH hOldBrush;
	hOldBrush = (HBRUSH)SelectObject(m_hBufferDC, hBrush);

	m_pBox->Draw(mViewConvert);

	SelectObject(m_hBufferDC, hOldBrush);
	DeleteObject(hBrush);

	GraphicsRelease();
}


void cGame::Release()
{
	if (m_pBox)		delete m_pBox;
	if (m_pViewer)	delete m_pViewer;
	if (s_this)		delete s_this;
}


cGame* cGame::GetGameSingleTone()
{
	if (!s_this)
		s_this = new cGame;

	return s_this;
}


void cGame::GraphicsInit()
{
	m_hdc = GetDC(m_hWnd);
	m_hBufferDC = CreateCompatibleDC(m_hdc);
	cMesh::s_hdc = m_hBufferDC;

	RECT rt = { 0, 0, 1000, 1000 };
	SelectObject(m_hBufferDC, m_bmpBack);
	FillRect(m_hBufferDC, &rt, (HBRUSH)GetStockObject(GRAY_BRUSH));
}


void cGame::GraphicsRelease()
{
	BitBlt(m_hdc, 0, 0, 1000, 1000, m_hBufferDC, 0, 0, SRCCOPY);

	DeleteDC(m_hBufferDC);
	ReleaseDC(m_hWnd, m_hdc);
}


HRESULT cGame::MessageHandler(UINT iMsg, WPARAM wp, LPARAM lp)
{
	return E_NOTIMPL;
}
