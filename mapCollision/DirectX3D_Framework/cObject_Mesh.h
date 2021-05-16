#pragma once
#include "cObject.h"

class cObject_Mesh :
	public cObject
{
protected:
	
public:
	cObject_Mesh();
	~cObject_Mesh();
	void Setup();
	void Update();
	void Render();
	bool IsPicked(cVec3 vDir,cVec3 vPos);
	void MoveObject(cVec3* pvDir, cVec3* pvPos, cVec3* pvNormal);
	void ConvertSize(cVec3* pvDir);
};

