#include "stdafx.h"
#include "cMaterial.h"


cMaterial::cMaterial()
	: m_pTexture(NULL)
{
	ZeroMemory(&m_mtl, sizeof(D3DMATERIAL9));
}


cMaterial::~cMaterial()
{
}


pTexture cMaterial::GetTextrue()
{
	return m_pTexture;
}


D3DMATERIAL9* cMaterial::GetMaterial()
{
	return &m_mtl;
}


void cMaterial::SetTexture(pTexture pTex)
{
	m_pTexture = pTex;
}
