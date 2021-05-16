// Math.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cVector3.h"
#include "cMatrix.h"


int _tmain(int argc, _TCHAR* argv[])
{
	cVector3 v1, v2(3, 4, - 1);

	v1 = -v2;
	v1.Print();

	cMatrix matrix = cMatrix::Random(4);
	cMatrix::Identity(4).Print();

	matrix.Print();
	float f = 0;

	matrix.Transpose().Print();
	
	cMatrix inverseM = matrix.Inverse2(f);
	inverseM.Print();

	cMatrix tem = matrix.Inverse(f);
	tem.Print();
	
	(matrix*inverseM).Print();

	return 0;
}

