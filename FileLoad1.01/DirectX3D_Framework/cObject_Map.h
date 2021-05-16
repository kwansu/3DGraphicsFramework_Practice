#pragma once

#include "cObject.h"
class cObject_Map :
	public cObject
{
private:
	
public:
	cObject_Map();
	~cObject_Map();
	void Setup();
	void Update();
	void Render();
};

