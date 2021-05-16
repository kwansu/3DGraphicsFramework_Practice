#include "stdafx.h"
#include "cObject_Map.h"


cObject_Map::cObject_Map()
{
	SetScale(0.1f, 0.1f, 0.1f);
	m_fAngleX = -90;
	UpdateWorld();
}


cObject_Map::~cObject_Map()
{
}


void cObject_Map::Setup()
{
}


void cObject_Map::Update()
{
}


void cObject_Map::Render()
{
	g_pDevice->SetTransform(D3DTS_WORLD, &m_matWolrd);
	g_pGraphics->Render();
}
