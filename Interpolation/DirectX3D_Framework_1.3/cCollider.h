#pragma once
#include "cColliderGroup.h"

// �浹ü.
// �浹�� ���� ������ ����ü.
// ��ü�� �浹������ ���ؼ��� �ϳ��̻��� �浹ü��
// �����ͷ� ������ �浹�˻縦 �ؾ��Ѵ�.

class cCollider
{
private:
	map<string, cColliderGroup>	m_mapColliderData;

public:
	cCollider();
	~cCollider();
	cColliderGroup* PushCollider(string name);
};

