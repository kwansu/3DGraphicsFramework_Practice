#pragma once
class cTransform
{
protected:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vDir;
	D3DXVECTOR3		m_vRot;

	D3DXMATRIXA16	m_matWorld;
	D3DXMATRIXA16	m_matS, m_matR, m_matT;

public:
	cTransform();
	~cTransform();

	// ������Ʈ �⺻ ���:
	virtual void SetPosition(const D3DXVECTOR3* pvPos);
	virtual void SetDirection(const D3DXVECTOR3* pvDir);
	virtual void SetPosition(float px, float py, float pz);
	virtual void SetRotation(float rx, float ry, float rz);
	virtual void SetScale(float sx, float sy, float sz);
	virtual void SetWorldMatirx(const D3DXMATRIXA16* pmatWorld);
	virtual void SetWorldMatirxFromParent(const D3DXMATRIXA16* pmatWorld);

	// ���� ������Ʈ�� ��ġ, ȸ���������� ��Ʈ������ �����ϴ� �Լ�
	virtual void UpdateTranslation();
	virtual void UpdateRotation();
	virtual void UpdateDirection();			//������Ʈ�� ���⺤�͸� ����. ������ ���� ��������͸� *������ ȸ����ķ�* ��ȯ.
	virtual void UpdateWorld();

	// ������Ʈ�� ���� ��Ʈ���������� D3DXVECTOR3�� ��ȯ�����ִ� �Լ�
	virtual void TransformPosition(OUT D3DXVECTOR3* pvOut);
	virtual void TransformVector(OUT D3DXVECTOR3* pvOut);
};

