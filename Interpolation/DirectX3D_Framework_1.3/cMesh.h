#pragma once
#include "cMeshGroup.h"

// ���ؽ�->������->��Ʈ(�׷�)->�Ž�(��ü�� ���)
// ������ ���� ���ؽ��� ����ü, ��ü�� ȭ�鿡 �׷��������ؼ���
// �ϳ��̻��� �Ž��� �����ͷ� ������ �ڽ��� ��ġ(���� ��Ʈ����)��
// �����Լ��� ȣ���ϸ� �ȴ�.

class cMesh
{
private:
	map<string, cMeshGroup>		m_mapMeshData;
	
public:
	cMesh();
	~cMesh();
	cMeshGroup* PushMesh(string name);
	void Render();
};

