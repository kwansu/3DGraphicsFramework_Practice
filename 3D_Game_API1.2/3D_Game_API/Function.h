#pragma once
#include "stdafx.h"

inline bool EqualFloat(float f1, float f2)
{
	return abs(f1 - f2) < EPSILON ? true : false;
}