#pragma once
class cObject
{
protected:
	D3DXVECTOR3		m_vLook, m_vUp, m_vRight;
	float			m_fAngleX, m_fAngleY;		//�� ��ȸ�� degree��. ������ ���� ������ 0�� ����.
	D3DXMATRIXA16	m_matWolrd, m_matScale;
	D3DXMATRIXA16	m_matTrl, m_matRot;

public:
	D3DXVECTOR3		m_vPos;
	cObject();
	virtual ~cObject();

	// ������Ʈ �������̽�
	virtual void Setup() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	// ������Ʈ �⺻ ���:
	void SetPosition(const D3DXVECTOR3* pvPos);
	void SetPosition(float px, float py, float pz);
	void SetRotation(float rx, float ry, float rz);
	void SetScale(float sx, float sy, float sz);
	void SetWorldMatirx(const D3DXMATRIXA16* pmatWorld);

	// ���� ������Ʈ�� ��ġ, ȸ���������� ��Ʈ������ �����ϴ� �Լ�
	void UpdateTranslation();
	void UpdateRotation();
	void UpdateWorld();
	void UpdateDirection();			//������Ʈ�� ���⺤�͸� ����. ������ ���� ��������͸� *������ ȸ����ķ�* ��ȯ.

	// ������Ʈ�� ���� ��Ʈ���������� D3DXVECTOR3�� ��ȯ�����ִ� �Լ�
	void TransformPosition(D3DXVECTOR3* pvOut);
	void TransformVector(D3DXVECTOR3* pvOut);
};

