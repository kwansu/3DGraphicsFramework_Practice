#pragma once

// ��ü �Ҵ縶�� �����Ǵ� ����ī����
// �ڿ��� �Ҵ��, ����� �����Ǵ��� Ȯ���ϴ� �뵵.

class cReferrers
{
private:
	int m_nRefCount;

public:
	cReferrers();
	~cReferrers();
	void AddRef();
	void Release();
};

