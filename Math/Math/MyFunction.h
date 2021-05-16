#pragma once
#include <math.h>


#define EPSILON 0.0001

inline bool IsInEpsilon(float val1, float val2
			, float epsilon = 0.0001)
{
	return abs(val1 - val2) < epsilon ? true : false;
}

inline float SetZeroEpsilon(float val)
{
	if (IsInEpsilon(val, 0))
		return val = 0;

	return val;
}