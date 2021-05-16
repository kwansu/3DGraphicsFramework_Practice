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
	// 중심점을 기준으로 월드좌표 z축 회전, 로컬좌표의 right축 회전
	void RotateAt(float fAngleZ, float fAngleR);
};

