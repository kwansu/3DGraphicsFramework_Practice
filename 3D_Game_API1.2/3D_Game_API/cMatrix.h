#pragma once
#include "cVector4.h"


class cMatrix
{
public:
	float** m_arr;
	int m_nDimension;

public:
	cMatrix(const cMatrix& copy);
	cMatrix(int nDimension);
	~cMatrix();
	
	static cMatrix Identity(int nDimension);
	static cMatrix Random(int nDimension); // -10~10
	cMatrix Transpose();
	cMatrix Inverse(float& fDef);

	bool operator==(const cMatrix& matrix);
	bool operator!=(const cMatrix& matrix);
	cMatrix operator=(const cMatrix& matrix);
	cMatrix operator+(const cMatrix& matrix);
	cMatrix operator-(const cMatrix& matrix);
	cMatrix operator*(const cMatrix& matrix);
	cMatrix operator*(float scalar);
	cMatrix operator/(float scalar);

	// 선형방정식소거법
	cMatrix Inverse();
	void MultiplyRow(float val, float*& row);
	void AddRow(float*& rowPur,float*& row, float fMul);
};

