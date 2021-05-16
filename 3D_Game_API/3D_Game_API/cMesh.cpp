#include "stdafx.h"
#include "cMesh.h"

HDC cMesh::s_hdc = NULL;


cMesh::cMesh()
{
}


cMesh::~cMesh()
{
}


void cMesh::Draw(const cMatrix4& mVeiwConvert)
{
	//각 점들은 로컬좌표. 월드변환 행렬과 뷰행렬을 곱해서 사용.
	for (int i = 0; i < m_arrVertex.size(); ++i)
		m_arrVertexCopy[i] = mVeiwConvert * m_arrVertex[i];

	for (int i = 0; i < m_arrMeshData.size(); ++i)
	{
		if (IsFront(i))
		{
			POINT pt[3];
			pt[0] = m_arrVertexCopy[m_arrMeshData[i].m_nFirst];
			pt[1] = m_arrVertexCopy[m_arrMeshData[i].m_nSecond];
			pt[2] = m_arrVertexCopy[m_arrMeshData[i].m_nThird];
			pt[0] = m_arrVertexCopy[m_arrMeshData[i].m_nFirst];

			Polygon(s_hdc, pt, 3);

			/*MoveToEx(s_hdc, m_arrVertexCopy[m_arrMeshData[i].m_nFirst].x
				, m_arrVertexCopy[m_arrMeshData[i].m_nFirst].y, NULL);
			LineTo(s_hdc, m_arrVertexCopy[m_arrMeshData[i].m_nSecond].x
				, m_arrVertexCopy[m_arrMeshData[i].m_nSecond].y);
			LineTo(s_hdc, m_arrVertexCopy[m_arrMeshData[i].m_nThird].x
				, m_arrVertexCopy[m_arrMeshData[i].m_nThird].y);
			LineTo(s_hdc, m_arrVertexCopy[m_arrMeshData[i].m_nFirst].x
				, m_arrVertexCopy[m_arrMeshData[i].m_nFirst].y);*/
		}
	}
}


bool cMesh::IsFront(int& i)
{
	cVector3 v1 = m_arrVertexCopy[m_arrMeshData[i].m_nSecond]
		- m_arrVertexCopy[m_arrMeshData[i].m_nFirst];
	cVector3 v2 = m_arrVertexCopy[m_arrMeshData[i].m_nThird]
		- m_arrVertexCopy[m_arrMeshData[i].m_nFirst];

	v1 = cVector3::Cross(v1, v2);

	if (cVector3::Dot(v1, cVector3(0, 0, 1)) < 0)
		return true;

	return false;
}
