#include "stdafx.h"
#include "cGame.h"

cGame* cGame::m_this = NULL;


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
}


void cGame::Render()
{
	m_hdc = GetDC(m_hWnd);

	cVector4 posView(4, 10, 10, 1);
	cVector4 posAt(0, 0, 0, 1);

	cMatrix4 mViewConvert = cMatrix4::View(&posView, &posAt, &cVector3(0, 0, 1))
		 * cMatrix4::Projection(45.f, 16.f / 9, 2.f, 20.f) * cMatrix4::Viewport(1600.f, 900.f);

	posAt = mViewConvert * posAt;

	for (int i = 0; i < m_arrVertex.size(); ++i)
		m_arrTrans[i] = mViewConvert * m_arrVertex[i];

	for (int i = 0; i < m_arrVertex.size(); ++i)
	{
		MoveToEx(m_hdc, m_arrTrans[i].x, m_arrTrans[i].y, NULL);
		++i;
		LineTo(m_hdc, m_arrTrans[i].x, m_arrTrans[i].y);
	}

	ReleaseDC(m_hWnd, m_hdc);
}


void cGame::Release()
{
	if (m_this)
		delete m_this;
}


cGame* cGame::GetGameSingleTone()
{
	if (!m_this)
		m_this = new cGame;

	return m_this;
}
