#pragma once

class cMaterial
{
private:
	D3DMATERIAL9	m_mtl;
	pTexture		m_pTexture;

public:
	cMaterial();
	~cMaterial();
	pTexture GetTextrue();
	D3DMATERIAL9* GetMaterial();
	void SetTexture(pTexture pTex);
};

