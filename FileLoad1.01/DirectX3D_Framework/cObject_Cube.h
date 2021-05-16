#pragma once
#include "cObject.h"
#include "cObject_Collider.h"

class cObject_Cube :
	public cObject
{
protected:
	vector<cVec3>		m_aLocalPos;
	//vector<Vertex_PC>	m_aVertexPC;
	vector<Vertex_PN>	m_aVertexPN;
	vector<Vertex_PNT>	m_aVertexPNT;
	cObject_Collider*	m_pCollider;
	pTexture			m_pTexture;
	D3DMATERIAL9		m_stMaterial;

public:
	cObject_Cube();
	~cObject_Cube();
	void Setup();
	void Update();
	void Render();
	// 3차원 회전가능한 박스충돌 함수.
	bool CubeCollision(cObject_Cube* pObject);
	bool IsCollision(cObject_Cube* pObject);
	// AABB충돌검사. 충돌시, 충돌범위를 채워준다.
	bool CollisionDetection(cVec3* pvOut, cObject_Cube* pConflictor);
	void TransformVertexMin(cVec3* pvOut);
	void TransformVertexMax(cVec3* pvOut);
	void SetLocalSize(float sx, float sy, float sz);
	cObject_Collider* GetCollider();
	void SetTexture();
	bool IsPicked(cVec3* pvDir, cVec3* pvPos);
	void MoveObject(cVec3* pvDir, cVec3* pvPos, cVec3* pvNormal);
};

