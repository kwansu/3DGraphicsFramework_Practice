#pragma once
#include "cObject.h"

class cObject_Viewer :
	public cObject
{
private:
	float m_fFovY;
	float m_fAspect;
	float m_fNear, m_fFar;
	float m_fWidth, m_fHeight;
	float m_fDistance;
	
	cVector4* m_posAt;
public:
	cObject_Viewer();
	~cObject_Viewer();
	cMatrix4 GetViewConvert();
	void SetFovY(float fFovY);
	bool SetViewRange(float fNear, float fFar);
	void SetViewSize(float fWidth, float fHeight);
	void Initialize(HWND hWnd, cVector4* p);
	void Update();
	// �߽����� �������� ������ǥ z�� ȸ��, ������ǥ�� right�� ȸ��
	void RotateAt(float fAngleZ, float fAngleR);
};

