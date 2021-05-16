#pragma once

// 충돌체.
// 충돌을 위한 점들의 집합체.
// 객체가 충돌판정을 위해서는 하나이상의 충돌체를
// 포인터로 가지고 충돌검사를 해야한다.

class cCollider	: public cReferrers
{
public:
	cCollider();
	~cCollider();
};

