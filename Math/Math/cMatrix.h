#pragma once


class cMatrix
{
private:
	float** m_arr;
	int m_nDimension;

public:
	cMatrix(const cMatrix& copy);
	cMatrix(int nDimension);
	~cMatrix();
	
	static cMatrix Identity(int nDimension);
	cMatrix Transpose();
	cMatrix Inverse(float& fDet);
	cMatrix Inverse2(float& fDet);
	static cMatrix Random(int nDimension); // -10~10
	void Print();

	bool operator==(const cMatrix& matrix);
	bool operator!=(const cMatrix& matrix);
	cMatrix operator+(const cMatrix& matrix);
	cMatrix operator-(const cMatrix& matrix);
	cMatrix operator*(const cMatrix& matrix);
	cMatrix operator*(float scalar);
	cMatrix operator/(float scalar);

	// 선형방정식소거법
	cMatrix Inverse();
	void MultiplyRow(float val, float*& row);
	void AddRow(float*& rowPur,float*& row, float fMul);
	// i, j는 삭제할 행과 열.
	cMatrix GetSmallMatrix(int i, int j);
	float GetMatrixValue();
	float GetC(int i, int j);
};

